#ifndef RLP_RLP_ENCODE_H
#define RLP_RLP_ENCODE_H

#include <rlp/items/rlpstring.hpp>

namespace verified {
    namespace rlp {
        class RLPEncoder {
            private:
                static buffer_t EncodeLength(const int len, const int offset);
                static buffer_t Encode(const buffer_t bytes_value);

            public:
            
                static buffer_t EncodeString(RLPString input);
                static buffer_t EncodeString(const std::string input);

                static buffer_t EncodeByteList(const buffer_array_t& input);
        };

    }   
}

#endif
