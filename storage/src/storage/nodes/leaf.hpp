#ifndef PMT_LEAF_NODE_H
#define PMT_LEAF_NODE_H

#include <storage/nodes/node.hpp>

class Leaf : public Node {
    private:
        nibble_t nibbles_;

    public:
        Leaf();
        // ~Leaf();

        Leaf(nibble_t nibbles, buffer_t value);

        static nibble_t EncodeKey(const nibble_t& input);
        static nibble_t DecodeKey(const nibble_t& input);
        
        nibble_t GetKey();
        void SetKey(nibble_t input);
        nibble_t EncodedKey();

        buffer_array_t Raw();
};

#endif