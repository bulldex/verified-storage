#ifndef RLP_RLP_STRING_H
#define RLP_RLP_STRING_H

#include <string>

#include <constants/alias.hpp>

namespace verified {
    namespace rlp {
        class RLPString {
            private:
                buffer_t _bytes;
                RLPString(const buffer_t bytes);

            public:
                buffer_t GetBytes();
                std::string AsHexString();
                static RLPString Create(const buffer_t input);
                static RLPString Create(const char input);
                static RLPString Create(const uint64_t input);
                static RLPString Create(const long input);
                static RLPString Create(const std::string input);
        };
    }
}

#endif
