#include "batchdbop.hpp"

#include <string>

BatchDBOp::BatchDBOp(const std::string& type, const buffer_t& key) {
    type_ = type;
    key_ = key;
    value_ = {};
}

BatchDBOp::BatchDBOp(const std::string& type, const buffer_t& key, const buffer_t& value) {
    type_ = type;
    key_ = key;
    value_ = value;
}

std::string BatchDBOp::GetType() {
    return type_;
}

void BatchDBOp::GetType(const std::string& type) {
    type_ = type;
}

buffer_t BatchDBOp::GetKey() {
    return key_;
}

void BatchDBOp::SetKey(const buffer_t& key) {
    key_ = key;
}

buffer_t BatchDBOp::GetValue() {
    return value_;
}

void BatchDBOp::SetValue(const buffer_t& value) {
    value_ = value;
}
