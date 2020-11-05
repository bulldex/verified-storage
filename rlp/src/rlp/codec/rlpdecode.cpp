#include "rlpdecode.hpp"

#include <constants/alias.hpp>
#include <utils/hex.hpp>

#include <rlp/items/rlpstring.hpp>


buffer_t verified::rlp::RLPDecoder::Decode(const buffer_t& bytes_input) {
    buffer_t decoded_;
    const auto first_byte_ = bytes_input[0];
    int length_ {0};

    if(first_byte_ <= SHORT_STRING) {
        // a single byte whose value is in the [0x00, 0x7f] range, that byte is its own RLP encoding.
        decoded_ = bytes_input;
    } else if(first_byte_ == NON_VALUE_STRING) {
        // Non value whose value is 0x80
        decoded_ = verified::utils::EmptyByte();
    } else if(first_byte_ <= LONG_STRING) {
        // string is 0-55 bytes long. 
        // A single byte with value 0x80 plus the length of the string followed by the string
        // The range of the first byte is [0x80, 0xb7]
        length_ = first_byte_ - (SHORT_STRING + 1);
        decoded_ = verified::utils::Slice(bytes_input, 1, length_);
    } else if(first_byte_ <= 0xbf) {
        // string is more than 55 bytes long. 
        // A single byte with value 0xb7 plus the length of length of the string followed by the string.
        // The range of the first byte is [0xb8, 0xbf]
        auto l_length_ = first_byte_ - LONG_STRING;
        auto length_ = bytes_input.size() - (l_length_ + 1);

        decoded_ = verified::utils::Slice(bytes_input, l_length_ + 1, length_ + 1); // + 1 for first byte length
    } else if(first_byte_ <= 0xf7) {
        // a list between 0-55 bytes long
        length_ = first_byte_ - 0xbf;
        auto inner_reminder = verified::utils::Slice(bytes_input, 1, length_);
        // while(inner_reminder.size()) {
        //     auto 
        // }
    } else {
        // a list over 55 bytes long
    }

    return decoded_;
}


std::string verified::rlp::RLPDecoder::DecodeByte(const buffer_t& input) {
    if(input.empty()) {
        return verified::utils::BytesToString(verified::utils::EmptyByte());
    }

    const buffer_t decoded_ = Decode(input);
    
    return verified::utils::BytesToString(decoded_);
}


std::string verified::rlp::RLPDecoder::DecodeString(const std::string& input) {
    if(input.empty()) {
        return verified::utils::BytesToString(verified::utils::EmptyByte());
    }

    const buffer_t byte_input_ = verified::utils::ToBytes(input);
    const buffer_t decoded_ = Decode(byte_input_);

    return verified::utils::BytesToString(decoded_);
}


buffer_array_t verified::rlp::RLPDecoder::DecodeByteList(const buffer_t &input) {
    // Todo complete this
    buffer_array_t bytes_array_;
    bytes_array_[0] = input;
    return bytes_array_;
}