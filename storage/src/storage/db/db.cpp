#include "db.hpp"

#include <leveldb/write_batch.h>
#include <string>

#include <constants/alias.hpp>
#include <constants/macros.hpp>

#include <utils/hex.hpp>
#include <storage/utils/aliasadvance.hpp>
#include <storage/utils/batchdbop.hpp>

DBConnection::DBConnection() {
    db_file_ = DEFAULT_DB_FILE;

    leveldb::Options options;
    options.create_if_missing = true;
    
    status_ = leveldb::DB::Open(options, db_file_, &db_);
}

DBConnection::DBConnection(const std::string &db_file) {
    db_file_ = db_file;

    leveldb::Options options;
    options.create_if_missing = true;
    
    status_ = leveldb::DB::Open(options, db_file, &db_);
}

DBConnection::DBConnection(leveldb:: DB* &db, const std::string &db_file, const leveldb::Status &status, const std::map<std::string, std::string> &uncommitted) {
    db_file_ = db_file;
    db_ = db;
    status_ = status;
    uncommitted_ = uncommitted;
}

bool DBConnection::operator!() {
    return !db_file_.empty() && status_.ok() && db_;
}

leveldb::Status DBConnection::GetStatus() {
    return status_;
}

buffer_t DBConnection::Get(const buffer_t &key) {
    std::string value_ {""};
    buffer_t result;
    const std::string key_ = verified::utils::BytesToString(key);

    auto iterator_ = uncommitted_.find(key_);

    if(iterator_ != uncommitted_.end()) {
        result = verified::utils::StringToBytes(iterator_->second);
    } else {
        status_ = db_->Get(leveldb::ReadOptions(), key_, &value_);

        if(status_.ok()) {
            result = verified::utils::StringToBytes(value_);
        } else {
            // Todo use try catch to throw error
        }
    }

    return result;
}

void DBConnection::Put(const buffer_t &key, const buffer_t &value) {
    const std::string key_ = verified::utils::BytesToString(key);
    std::string value_ = verified::utils::BytesToString(value);

    uncommitted_.insert(std::make_pair(key_, value_));
}

void DBConnection::Delete(const buffer_t &key) {
    const std::string key_ = verified::utils::BytesToString(key);

    auto iterator_ = uncommitted_.find(key_);

    if(iterator_ != uncommitted_.end()) {
        uncommitted_.erase(key_);
    } else {
        status_ = db_->Delete(leveldb::WriteOptions(), key_);
    }
}

void DBConnection::Commit() {
    leveldb::WriteBatch bacth_;
    leveldb::WriteOptions opt_;
    opt_.sync = true;
   
    std::map<std::string, std::string>::iterator it_;
    for(it_ = uncommitted_.begin(); it_ != uncommitted_.end(); it_++) {
        bacth_.Put(it_->first, it_->second);
    }
    status_ = db_->Write(opt_, &bacth_);
    uncommitted_.clear();
}

std::map<buffer_t, buffer_t> DBConnection::ReadAll() {
    std::map<buffer_t, buffer_t> key_values_;

    leveldb::Iterator *it = db_->NewIterator(leveldb::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next()) {
        auto key_ = it->key().ToString();
        auto value_ = it->value().ToString();
        key_values_.insert(std::make_pair(verified::utils::StringToBytes(key_), verified::utils::StringToBytes(value_)));
    }
    delete it;

    return key_values_;
}

void DBConnection::BatchProcess(const batchdboparray_t &ops) {
    for(BatchDBOp element : ops) {
        if(element.GetType() == "put") {
            if(element.GetValue().empty()) {
                // Todo Throw error
                break;
            }
            Put(element.GetKey(), element.GetValue());
        } else if(element.GetType() == "del") {
            Delete(element.GetKey());
        }
    }

    if(uncommitted_.size() > 0) {
        Commit();
    }

}

DBConnection DBConnection::Copy() {
    return DBConnection(db_, db_file_, status_, uncommitted_);
}
