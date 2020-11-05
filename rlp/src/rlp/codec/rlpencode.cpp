#include "rlpencode.hpp"

#include <constants/macros.hpp>
#include <utils/hex.hpp>

#include <rlp/items/rlpstring.hpp>

buffer_t verified::rlp::RLPEncoder::EncodeLength(const int len, const int offset) {
    buffer_t encode_length_;
    if (len <= SINGLE_BYTE_STRING) {
        encode_length_ = verified::utils::IntegerToBytes(len + offset);
    } else {
        const std::string hex_len_ = verified::utils::IntegerToHex(len);
        buffer_t second_part_ = verified::utils::StringToBytes(hex_len_);

        const auto l_length_ = second_part_.size();
        const auto number_ = offset + l_length_;
        encode_length_ = verified::utils::IntegerToBytes(number_);
        encode_length_.insert(encode_length_.end(), second_part_.begin(), second_part_.end());
    }

    return encode_length_;
}

buffer_t verified::rlp::RLPEncoder::Encode(const buffer_t bytes_value) {
    buffer_t encode_;

    if (bytes_value.empty() || (bytes_value.size() == 1 && bytes_value.at(0) == EMPTY_STRING)) {
        // The input is non value
        encode_.push_back(NON_VALUE_STRING);
    } else if(bytes_value.size() == 1 && bytes_value.at(0) <= SHORT_STRING) {
        // It's a single byte between [0x00, 0x7f]
        encode_ = bytes_value;
    } else if(bytes_value.size() == 1 && (bytes_value.at(0) > SHORT_STRING && bytes_value.at(0) <= LAST_STRING)) {
        // It's a single byte between [0x80, 0xff]
        encode_ = EncodeLength(bytes_value.size(), SHORT_STRING + 1);
        encode_.insert(encode_.end(), bytes_value.begin(), bytes_value.end());
    } else if(bytes_value.size() <= 55) {
        // It's 2-55 byte string
        encode_ = EncodeLength(bytes_value.size(), SHORT_STRING + 1);
        encode_.insert(encode_.end(), bytes_value.begin(), bytes_value.end());
    } else if(bytes_value.size() > 55) {
        // It's a string with more than 55 bytes long.
        encode_ = EncodeLength(bytes_value.size(), LONG_STRING);
        encode_.insert(encode_.end(), bytes_value.begin(), bytes_value.end());
    }

    return encode_;
}

buffer_t verified::rlp::RLPEncoder::EncodeString(RLPString input) {
    return Encode(input.GetBytes());
}

buffer_t verified::rlp::RLPEncoder::EncodeString(const std::string input) {
    RLPString rlp_str_ = RLPString::Create(input);
    return EncodeString(rlp_str_);
}
