#include "path.hpp"

Path::Path() {
    // All the path values are empty
    status_ = false;
}

Path::Path(const node_t &node, const nibble_t &remaining, const std::vector<node_t> &stack) {
    node_ = node;
    remaining_ = remaining;
    stack_ = stack;
    status_ = !node.empty();
}

node_t Path::GetNode() {
    return node_;
}

void Path::SetNode(const node_t &node) {
    node_ = node;
}

nibble_t Path::GetRemaining() {
    return remaining_;
}

void Path::SetRemaining(const nibble_t &remaining) {
    remaining_ = remaining_;
}

std::vector<node_t> Path::GetStack() {
    return stack_;
}

void Path::SetStack(const std::vector<node_t> &stack) {
    stack_ = stack;
}

bool Path::GetStatus() {
    return status_;
}

void Path::SetStatus(const bool status) {
    status_ = status;
}
