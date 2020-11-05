#include "foundnode.hpp"

FoundNode::FoundNode(const buffer_t &node_ref, const node_t &node, const nibble_t &key, std::string controller_type) {
    node_ref_ = node_ref;
    node_ = node;
    key_ = key;
    controller_type_ = controller_type;
}

buffer_t FoundNode::GetNodeRef() {
    return node_ref_;
}

void FoundNode::SetNodeRef(const buffer_t &node_ref) {
    node_ref_ = node_ref;
}

node_t FoundNode::GetNode() {
    return node_;
}

void FoundNode::SetNode(const node_t &node) {
    node_ = node;
}

nibble_t FoundNode::GetKey() {
    return key_;
}

void FoundNode::SetKey(const nibble_t &key) {
    key_ = key;
}

std::string FoundNode::GetControllerType() {
    return controller_type_;
}

void FoundNode::SetControllerType(const std::string &controller_type) {
    controller_type_ = controller_type;
}
