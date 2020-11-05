#ifndef PMT_NODE_UTILS_H
#define PMT_NODE_UTILS_H

#include <constants/alias.hpp>
#include <storage/utils/aliasadvance.hpp>
#include <storage/nodes/node.hpp>

bool IsRawNode(const embedded_t &input);

node_t DecodeRawNode(const buffer_array_t &input);

node_t DecodeNode(const buffer_t &input);


#endif