#ifndef PMT_BRANCH_NODE_H
#define PMT_BRANCH_NODE_H

#include <map>

#include <storage/nodes/node.hpp>

class Branch : public Node {
    private:
        buffer_array_t branches_;

    public:
        Branch();
        // ~Branch();

        static Node FromBuffer(const buffer_array_t &input);
        void SetBranch(const int loc, const buffer_t &input);
        buffer_t GetBranch(const int input);
        buffer_array_t GetBranches();
        std::map<nibble_t, buffer_t> GetChildren();

        buffer_array_t Raw();
};

#endif