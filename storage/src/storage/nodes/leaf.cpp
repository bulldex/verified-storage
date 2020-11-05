#include "leaf.hpp"

#include <constants/enums.hpp>
#include <utils/nibbles.hpp>


Leaf::Leaf() {
    // It's empty leaf node
    node_type_ = LEAF_NODE;
}

Leaf::Leaf(nibble_t nibbles, buffer_t value) {
    nibbles_ = nibbles;
    value_ = value;
    node_type_ = LEAF_NODE;
}

nibble_t Leaf::EncodeKey(const nibble_t& input) {
    return verified::utils::AddHexPrefix(input, true);
}

nibble_t Leaf::DecodeKey(const nibble_t& input) {
    return verified::utils::RemoveHexPrefix(input);
}

nibble_t Leaf::GetKey() {
    return nibbles_;
}

void Leaf::SetKey(nibble_t input) {
    nibbles_ = input;
}

nibble_t Leaf::EncodedKey() {
    return Leaf::EncodeKey(nibbles_);
}

buffer_array_t Leaf::Raw() {
    buffer_array_t raw_;
    raw_.push_back(verified::utils::NibbleToByte(nibbles_));
    raw_.push_back(value_);
    return raw_;
}
