#ifndef PMT_EXTENSION_NODE_H
#define PMT_EXTENSION_NODE_H

#include <storage/nodes/node.hpp>

class Extension : public Node {
    private:
        nibble_t nibble_;

    public:
        Extension();
        Extension(nibble_t nibble, buffer_t value);
        // ~Extension();

        static nibble_t EncodeKey(const nibble_t& input);
        static nibble_t DecodeKey(const nibble_t& input);
        
        nibble_t GetKey();
        void SetKey(nibble_t input);
        nibble_t EncodedKey();

        buffer_array_t Raw();
};

#endif