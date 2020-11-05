#include "rlpstring.hpp" 

#include <utils/hex.hpp>

verified::rlp::RLPString::RLPString(const buffer_t input) {
    _bytes = input;
}

buffer_t verified::rlp::RLPString::GetBytes() {
    return _bytes;
}

std::string verified::rlp::RLPString::AsHexString() {
    return verified::utils::BytesToString(_bytes);
}

verified::rlp::RLPString verified::rlp::RLPString::Create(const buffer_t input) {
    return RLPString(input);
}

verified::rlp::RLPString verified::rlp::RLPString::Create(const uint64_t input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(verified::utils::EmptyByte());
    }
    buffer_t bytes_;
    bytes_.push_back(input);
    return RLPString(bytes_);
}

verified::rlp::RLPString verified::rlp::RLPString::Create(const char input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(verified::utils::EmptyByte());
    }
    buffer_t bytes_ = verified::utils::IntegerToBytes(input);
    return RLPString(bytes_);
}

verified::rlp::RLPString verified::rlp::RLPString::Create(const long input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(verified::utils::EmptyByte());
    }
    return Create((uint64_t)input);
}

verified::rlp::RLPString verified::rlp::RLPString::Create(const std::string input) {
    if (input.empty()) {
        return Create(verified::utils::EmptyByte());
    }
    buffer_t bytes_ = verified::utils::StringToBytes(input);
    return RLPString(bytes_);
}
