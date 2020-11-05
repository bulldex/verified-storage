#include <iostream>

#include <utils/hex.hpp>
#include <rlp/items/rlpstring.hpp>
#include <rlp/codec/rlpencode.hpp>
#include <rlp/codec/rlpdecode.hpp>


int main() {
    std::cout << verified::utils::StringToBytes("Rahul").data() << std::endl;
    // std::cout << std::to_string(0x00) << std::endl;
    std::string original_str {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
    // std::string original_str {"1✁g"};
    // std::string original_str {"world"};

    std::vector<uint64_t> encoded_str = verified::rlp::RLPEncoder::EncodeString(original_str);
    std::cout << "Encoded: " << encoded_str.data() << std::endl;
    std::cout << verified::utils::GetBytes(encoded_str) << std::endl;

    std::string byte_str_ = verified::utils::BytesToString(encoded_str);
    std::string new_str_ = verified::rlp::RLPDecoder::DecodeByte(encoded_str);
    std::cout << "Decoded: " << new_str_ << std::endl;

    verified::rlp::RLPString test_ = verified::rlp::RLPString::Create(0L);
    std::vector<uint64_t> encoded_str_ = verified::rlp::RLPEncoder::EncodeString(test_);
    std::cout << verified::utils::GetBytes(encoded_str_) << std::endl;
    
    byte_str_ = verified::utils::BytesToString(encoded_str_);
    new_str_ = verified::rlp::RLPDecoder::DecodeString(byte_str_);
    std::cout << "Decoded: " << new_str_ << std::endl;

    return 0;
}
