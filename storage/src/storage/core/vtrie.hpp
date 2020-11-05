#ifndef PMT_VTRIE_H
#define PMT_VTRIE_H

#include <boost/variant.hpp>

#include <storage/utils/aliasadvance.hpp>
#include <storage/utils/path.hpp>
#include <storage/utils/batchdbop.hpp>
#include <storage/db/db.hpp>
#include <storage/nodes/node.hpp>
#include <storage/nodes/leaf.hpp>
#include <storage/nodes/branch.hpp>
#include <storage/nodes/extension.hpp>

class VTrie {
    private:
        bool _is_defined;
        buffer_t _EMPTY_TRIE_ROOT;
        buffer_t _root;
        DBConnection _db;
        // Todo Add Semaphore for locking the resource under processing

        /**
         * @brief Retrieves a node from db hash
         * 
         * @param node value for which node is to be retrieved
         * @return node_t Retrieved node
         */
        node_t LookupNode(const embedded_t &node);

        /**
         * @brief Writes a single node to db
         * 
         * @param node node to be put in db
         */
        void PutNode(node_t &node);
        
        /**
         * @brief Updates a node
         * 
         * @param key Key at which value is to be updated
         * @param value new value to be updated
         * @param key_reminder reminder of the key
         * @param stack TrieNode stack
         */
        void UpdateNode(const buffer_t &key, const buffer_t &value, nibble_t &key_reminder, std::vector<node_t> &stack);

        void OnFoundValues(const buffer_t &node_ref, const node_t &node, const nibble_t &key);
        void OnFoundDb(const buffer_t &node_ref, const node_t &node, const nibble_t &key);

        void FindValueNodes(const buffer_t &node_ref, node_t &node, const nibble_t &key);
        
        void FindDbNodes(const buffer_t &node_ref, const node_t &node, const nibble_t &key);
        
        Path OnNode(nibble_t &target_key, const buffer_t &node_ref, node_t &node, const nibble_t &key_progress, std::vector<node_t> &stack);

        Path WalkTrie(buffer_t &root, nibble_t &target_key);
        
        /**
         * @brief Saves a stack
         * 
         * @param key the key. Should follow the stack
         * @param stack stack of nodes to the value given by the key
         * @param op_stack stack of level db operations to commit at the end of the function
         */
        void SaveStack(nibble_t &key, std::vector<node_t> &stack, batchdboparray_t &op_stack);
        
        /**
         * @brief Process branch node before performing a delete operation
         * 
         * @param key key to be processed in a branch
         * @param branchKey branch key
         * @param branchNode branch node value
         * @param parentNode parent node of the value
         * @param stack stack of node
         * @return nibble_t processed branch key
         */
        nibble_t ProcessBranchNode(nibble_t &key, const uint_t &branchKey, node_t &branchNode, node_t &parentNode, std::vector<node_t> &stack);

        Path ProcessNode(const buffer_t &node_ref, node_t &node, const nibble_t &key, nibble_t &target_key);

        void WalkController(nibble_t &target_key, const node_t &node, const nibble_t &key, std::string controller_type, const nibble_t &child_index);

        /**
         * @brief deletes a node
         * 
         * @param key key to be deleted from the node
         * @param stack stack of nodes
         */
        void DeleteNode(const buffer_t &key, std::vector<node_t> &stack);
        
        /**
         * @brief Create a Initial Node form the empty tree
         * 
         * @param key Key of the node
         * @param value value associated with the key
         */
        void CreateInitialNode(const buffer_t &key, const buffer_t &value);
        
        /**
         * @brief Format node to be saved by leveldb batch processing
         * 
         * @param node the node to format
         * @param op_stack the op_stack to push the node's data
         * @param top_level if the node is at the top level
         * @param remove Whether to remove the node (Only used for checkoint Trie)
         * @return embedded_t The node's has used as key or raw node
         */
        embedded_t FormatNode(node_t &node, batchdboparray_t &op_stack, const bool top_level, const bool remove=false);

    public:
        /**
         * @brief Construct a new VTrie object
         * 
         */
        VTrie();
        
        // ~VTrie();
        
        /**
         * @brief Construct a new VTrie object
         * 
         * @param root 
         */
        VTrie(const buffer_t &root);

        /**
         * @brief Construct a new VTrie object
         * 
         * @param db 
         * @param root 
         */
        VTrie(DBConnection &db, const buffer_t &root);

        /**
         * @brief Get the Root object
         * 
         * @return buffer_t 
         */
        buffer_t GetRoot();

        /**
         * @brief Set the root value for the Trie
         * 
         * @param root root for Trie
         */
        void Root(const buffer_t &root);

        /**
         * @brief Set the Root object
         * 
         * @param root 
         */
        void SetRoot(const buffer_t &root);

        /**
         * @brief Get the isdefined status
         * 
         * @return true - defined
         * @return false - not defined
         */
        bool IsDefined();

        /**
         * @brief Set the is defined status
         * 
         * @param is_defined whether Trie is defined or not
         */
        void IsDefined(const bool is_defined);

        /**
         * @brief Database connection to leveldb
         * 
         * @return DBConnection leveldb database connection
         */
        DBConnection GetDB();
        
        /**
         * @brief Sets the leveldb database connection
         * 
         * @param db leveldb database connection
         */
        void SetDB(const DBConnection &db);

        /**
         * @brief Saves the nodes from proof into trie. If no trie is provided, a new one will be created
         * 
         * @param proof_nodes Nodes to be saved in the trie
         * @param proof_trie trie in which new nodes needs to be saved
         * @return VTrie Verified trie object
         */
        static VTrie FromProof(const buffer_array_t &proof_nodes, VTrie &proof_trie);

        /**
         * @brief Creates a proof from a trie and key that can be verified using VerifyProof
         * 
         * @param trie Trie to be verified
         * @param key Key to be checked
         * @return buffer_array_t Proof result
         */
        buffer_array_t Prove(VTrie &trie, const buffer_t &key);

        /**
         * @brief Verifies proof
         * 
         * @param root_hash root hash of the trie
         * @param key Key to be verified
         * @param proof_nodes proof nodes
         * @return buffer_t The value from the key
         */
        buffer_t VerifyProof(const buffer_t &root_hash, const buffer_t &key, const buffer_array_t &proof_nodes);

        /**
         * @brief Tries to find the path to the node for the given key.
         * It returns the stack of nodes to the closest node
         * 
         * @param key the search key
         * @return Path Stack of node, path, closest to the node
         */
        Path FindPath(const buffer_t &key);

        /**
         * @brief Create a new Trie from the same database
         * 
         * @return VTrie New Trie object
         */
        VTrie Copy();
        
        /**
         * @brief The given hash of operations (insertion or deletion) are executed on the DB
         * 
         * @example
         * batchdboparray_t ops;
         * operation_ = BatchDBOp("del", verified::utils::StringToBytes("father"));
         * ops.push_back(operation_);
         * BatchDBOp operation_ = BatchDBOp("put", verified::utils::StringToBytes("name"), verified::utils::StringToBytes("Rahul"));
         * ops.push_back(operation_);
         * operation_ = BatchDBOp("put", verified::utils::StringToBytes("dob"), verified::utils::StringToBytes("7 September 1986"));
         * ops.push_back(operation_);
         * operation_ = BatchDBOp("put", verified::utils::StringToBytes("spouse"), verified::utils::StringToBytes("Priyanka"));
         * ops.push_back(operation_);
         * operation_ = BatchDBOp("put", verified::utils::StringToBytes("occupation"), verified::utils::StringToBytes("Trainer"));
         * ops.push_back(operation_);
         * Batch(ops);
         * 
         * @param op_stack stack of operations to be performed
         */
        void Batch(const batchdboparray_t &op_stack);
        
        /**
         * @brief Checks if given root exists
         * 
         * @param root Root to be checked for existence
         * @return true - root exists
         * @return false - root does not exists
         */
        bool CheckRoot(const buffer_t &root);
        
        /**
         * @brief Gets a value given a key
         * 
         * @param key the key to search for
         * @return buffer_t The value associated with key or null
         */
        buffer_t Select(const buffer_t &key);

        /**
         * @brief Get's a value given a key and root hash
         * 
         * @param root_hash Root hash of the trie in which key is to be searched
         * @param key the key to search
         * @return buffer_t The value associated with the key or null
         */
        buffer_t Select(const buffer_t &root_hash, const buffer_t &key);

        /**
         * @brief Stores a given value at the given key
         * 
         * @param key key to store
         * @param value Value to be stored at the key
         * @return true if value is stored
         * @return false if any error occurs while storing the value at key
         */
        bool Put(const buffer_t &key, const buffer_t &value);
        
        /**
         * @brief Simpler version of Put
         * Stores a given value at the given key
         * 
         * @param key key to store
         * @param value Value to be stored at the key
         * @return key hash if successfull else error
         */
        std::string Insert(const std::string &key, const std::string &value);

        /**
         * @brief Deletes value given a key
         * 
         * @param key Key for which value is to be deleted
         * @return true If value deleted successfully
         * @return false If any error occures while deleting the value
         */
        bool Delete(const buffer_t &key);

        bool Update(const buffer_t &key, const buffer_t &value);

        // Operators
        // bool operator!();
};

#endif
