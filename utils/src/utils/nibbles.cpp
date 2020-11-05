#include "nibbles.hpp"

#include <utils/hex.hpp>                                                                                                                             

nibble_t verified::utils::StringToNibble(const std::string& input) {
    buffer_t buffer_ = StringToBytes(input);
    return ByteToNibble(buffer_);
}

std::string verified::utils::NibbleToString(const nibble_t& input) {
    buffer_t buffer_ = NibbleToByte(input);
    return BytesToString(buffer_);
}

nibble_t verified::utils::ByteToNibble(const buffer_t& input) {
    nibble_t nibbles_;
    nibbles_.resize(input.size() * 2);

    for(std::size_t i = 0; i < input.size(); i++) {
        int loc_ = i * 2;
        nibbles_.at(loc_) = input.at(i) >> 4;
        ++loc_;
        nibbles_.at(loc_) = nibbles_.at(i) % 16;
    }

    return nibbles_;
}

buffer_t verified::utils::NibbleToByte(const nibble_t& input) {
    buffer_t buffer_;
    buffer_.resize(input.size() / 2);

    for(std::size_t i = 0; i < buffer_.size(); i++) {
        int loc_ = i * 2;
        buffer_.at(i) = (input.at(loc_) << 4) + input.at(++loc_);
    }

    return buffer_;
}

int verified::utils::MatchingNibbleLength(const nibble_t& input_1, const nibble_t& input_2) {
    std::size_t i = 0;
    while((input_1.at(i) == input_2.at(i)) && input_1.size() > i) {
        i++;
    }

    return i;
}

bool verified::utils::DoKeysMatch(nibble_t& input_1, nibble_t& input_2) {
    int length_ = MatchingNibbleLength(input_1, input_2);
    return length_ == input_1.size() && length_ == input_2.size();
}

nibble_t verified::utils::AddHexPrefix(const nibble_t& input, bool terminator) {
    nibble_t bytes_;

    if(input.size() % 2) {
        bytes_.push_back(1);
    } else {
        bytes_.push_back(0);
        bytes_.push_back(0);
    }

    bytes_.insert(bytes_.end(), input.begin(), input.end());

    if(terminator) {
        bytes_.at(0) += 2;
    }

    return bytes_;
}

nibble_t verified::utils::RemoveHexPrefix(const nibble_t& input) {
    nibble_t bytes_;

    bytes_ = (input.at(0) % 2) ? Slice(input, 1) : Slice(input, 2);

    return bytes_;
}

bool verified::utils::IsTerminator(const nibble_t& input) {
    return input.at(0) > 1;
}
