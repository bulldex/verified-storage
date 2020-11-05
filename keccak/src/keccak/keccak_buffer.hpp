#ifndef PMT_KECCAK_BUFFER_T
#define PMT_KECCAK_BUFFER_T

#include "keccak.h"

#include <constants/alias.hpp>

class KeccakBuffer {
    private:
        Keccak keccak_;

    public:
        KeccakBuffer();
        KeccakBuffer(const Keccak::Bits bits);

        buffer_t operator()(const buffer_t& input);
};

#endif