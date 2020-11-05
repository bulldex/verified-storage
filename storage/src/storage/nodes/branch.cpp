#include "branch.hpp"

#include <map>

#include <constants/alias.hpp>
#include <constants/enums.hpp>
#include <utils/hex.hpp>

Branch::Branch() {
    branches_.reserve(16);
    node_type_ = BRANCH_NODE;
}

Node Branch::FromBuffer(const buffer_array_t &input) {
    buffer_array_t buffer_arr_(input);
    if(input.size() > 17) {
        buffer_arr_.resize(17);
    }
    
    Branch node_ = Branch();
    // Todo Create template for slicing stl array slice it instead of looping
    for(std::size_t i = 0; i < buffer_arr_.size() - 1; i++) {
        node_.SetBranch(i, buffer_arr_.at(i));
    }

    node_.SetValue(input.at(buffer_arr_.size() - 1));

    return node_;
}

void Branch::SetBranch(const int loc, const buffer_t &input) {
    branches_.at(loc) = input;
}

buffer_t Branch::GetBranch(const int input) {
    buffer_t branch_ = branches_.at(input);
    if(!branch_.empty() && branch_.size()) {
        return branch_;
    } else {
        return verified::utils::EmptyByte();
    }
}

buffer_array_t Branch::GetBranches() {
    return branches_;
}

buffer_array_t Branch::Raw() {
    buffer_array_t raw_;
    for(auto branch_ : branches_) {
        raw_.push_back(branch_);
    }
    raw_.push_back(value_);

    return raw_;
}

std::map<nibble_t, buffer_t> Branch::GetChildren() {
    std::map<nibble_t, buffer_t> children_;
    for(std::size_t i = 0; i <  16; i++) {
        auto branch_ = branches_.at(i);
        if(branch_.empty() && branch_.size()) {
            children_.insert(std::pair<int, buffer_t>(i, branch_));
        }
    }

    return children_;
}
