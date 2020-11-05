#ifndef RLP_RLP_LIST_H
#define RLP_RLP_LIST_H

#include <string>

#include <constants/alias.hpp>

namespace verified {
    namespace rlp {
        class RLPList {
            private:
                buffer_array_t _bytes;
                RLPList(buffer_array_t bytes);
            public:
                buffer_array_t GetBytes();
                // std::string AsHexString();
                static RLPList Create(const buffer_t& input);
                // static RLPList Create(const buffer_array_t& input);
                // static RLPList Create(const variant_t& input);
        };
    }
}

#endif
