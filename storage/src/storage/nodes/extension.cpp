#include "extension.hpp"

#include <constants/enums.hpp>
#include <utils/nibbles.hpp>

Extension::Extension() {
    // It's empty extension
    node_type_ = EXTENSION_NODE;
}

Extension::Extension(nibble_t nibble, buffer_t value) {
    nibble_ = nibble;
    value_ = value;
    node_type_ = EXTENSION_NODE;
}

nibble_t Extension::EncodeKey(const nibble_t& input) {
    return verified::utils::AddHexPrefix(input, false);
}

nibble_t DecodeKey(const nibble_t& input) {
    return verified::utils::RemoveHexPrefix(input);
}

nibble_t Extension::GetKey() {
    return nibble_;
}

void Extension::SetKey(nibble_t input) {
    nibble_ = input;
}

nibble_t Extension::EncodedKey() {
    return Extension::EncodeKey(nibble_);
}

buffer_array_t Extension::Raw() {
    buffer_array_t raw_;
    raw_.push_back(verified::utils::NibbleToByte(EncodedKey()));
    raw_.push_back(value_);
    return raw_;
}
