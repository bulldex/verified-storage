#ifndef PMT_BATCH_DB_OP_H
#define PMT_BATCH_DB_OP_H

#include <vector>
#include <string>

#include <constants/alias.hpp>

class BatchDBOp {
    private:
        std::string type_;
        buffer_t key_;
        buffer_t value_;
    
    public:
        BatchDBOp(const std::string &type, const buffer_t &key);
        BatchDBOp(const std::string &type, const buffer_t &key, const buffer_t &value);

        std::string GetType();
        void GetType(const std::string &type);
        
        buffer_t GetKey();
        void SetKey(const buffer_t &key);
        
        buffer_t GetValue();
        void SetValue(const buffer_t &value);

};

// using batchdboparray_t = std::vector<BatchDBOp>;

#endif
