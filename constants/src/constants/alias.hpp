#ifndef CONSTANTS_ALIAS_H
#define UTILS_ALIAS_H

#include <vector>
#include <stdint.h>
#include <boost/variant.hpp>

using uint_t = unsigned int;

using nibble_t = std::vector<uint_t>;

using buffer_t = std::vector<uint64_t>;

using buffer_array_t = std::vector<buffer_t>;

using variant_t = boost::variant<long, uint64_t, std::string, buffer_t, buffer_array_t>;

#endif