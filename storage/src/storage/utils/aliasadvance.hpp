#ifndef PMT_ALIAS_ADVANCE_H
#define PMT_ALIAS_ADVANCE_H

#include <boost/variant.hpp>
#include <vector>

#include <constants/alias.hpp>

#include <storage/nodes/leaf.hpp>
#include <storage/nodes/branch.hpp>
#include <storage/nodes/extension.hpp>
#include <storage/utils/batchdbop.hpp>

using embedded_t = boost::variant<buffer_t, buffer_array_t>;

using batchdboparray_t = std::vector<BatchDBOp>;

using node_t = boost::variant<Node, Branch, Extension, Leaf>;

#endif