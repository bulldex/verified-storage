#include "node.hpp"

#include <constants/enums.hpp>
#include <utils/hex.hpp>
#include <rlp/codec/rlpencode.hpp>
#include <keccak/keccak_buffer.hpp>


Node::Node() {
    node_type_ = BLANK_NODE;
}

Node::Node(const Node &node) {
    value_ = node.value_;
    node_type_ = node.node_type_;
}

char Node::GetNodeType() {
    return node_type_;
}

void Node::SetNodeType(char input) {
    node_type_ = input;
}

buffer_t Node::GetValue() {
    return value_;
}

void Node::SetValue(buffer_t input) {
    value_ = input;
}

buffer_array_t Node::Raw() {
    buffer_array_t raw_;
    raw_.resize(1, value_);

    return raw_;
}

buffer_t Node::Serialize() {
    return verified::rlp::RLPEncoder::EncodeByteList(Raw());
}

buffer_t Node::Hash() {
    KeccakBuffer buffer_hash_ = KeccakBuffer();
    return buffer_hash_(Serialize());
}
