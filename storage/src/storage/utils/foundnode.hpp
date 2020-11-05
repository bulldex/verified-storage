#ifndef PMT_FOUND_NODE_H
#define PMT_FOUND_NODE_H

#include <constants/alias.hpp>
#include <storage/utils/aliasadvance.hpp>

class FoundNode {
    private:
        buffer_t node_ref_;
        node_t node_;
        nibble_t key_;
        std::string controller_type_;
    public:
        FoundNode(const buffer_t &node_ref, const node_t &node, const nibble_t &key, std::string controller_type);

        buffer_t GetNodeRef();
        void SetNodeRef(const buffer_t &node_ref);
        node_t GetNode();
        void SetNode(const node_t &node);
        nibble_t GetKey();
        void SetKey(const nibble_t &key);
        std::string GetControllerType();
        void SetControllerType(const std::string &controller_type);
};

#endif