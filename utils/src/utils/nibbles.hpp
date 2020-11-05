#ifndef PMT_UTILS_NIBBLES_H
#define PMT_UTILS_NIBBLES_H

#include <vector>
#include <iostream>

#include <constants/alias.hpp>

namespace verified {
    namespace utils {
        /**
         * @brief Converts a string to nibble
         * 
         * @param input key to convert to nibble
         * @return nibble_t Nibble representation of the input
         */
        nibble_t StringToNibble(const std::string& input);

        /**
         * @brief Convert a nibble to string 
         * 
         * @param input value to be converted to string
         * @return std::string  String representation of the input
         */
        std::string NibbleToString(const nibble_t& input);

        /**
         * @brief Converts a byte to nibble
         * 
         * @param input key to convert to nibble
         * @return nibble_t Nibble representation of the input
         */
        nibble_t ByteToNibble(const buffer_t& input);

        /**
         * @brief Converts a nibble to byte
         * 
         * @param input Nibble to be converted to buffer
         * @return buffer_t Byte representation of the input
         */
        buffer_t NibbleToByte(const nibble_t& input);

        /**
         * @brief Match the number of inorder matching nibbles of the two given nubbles
         * 
         * @param input_1 First Nibble
         * @param input_2 Second nibble
         * @return int Number of matching nibbles
         */
        int MatchingNibbleLength(const nibble_t& input_1, const nibble_t& input_2);

        /**
         * @brief Compare two nibble keys
         * 
         * @param input_1 First Nibble
         * @param input_2 Second Nibble
         * @return true if the keys match
         * @return false if keys do not match
         */
        bool DoKeysMatch(nibble_t& input_1, nibble_t& input_2);

        /**
         * @brief Prepends hex prefix to nibble
         * 
         * @param input Nibble
         * @param terminator flag to indicate whether there is terminator string or not
         * @return nibble_t Hex Prefixed Nibble
         */
        nibble_t AddHexPrefix(const nibble_t& input, bool terminator);

        /**
         * @brief Removes Hex prefix of Nibble
         * 
         * @param input Nibble with hex prefixed
         * @return nibble_t Nibble without hex prefix
         */
        nibble_t RemoveHexPrefix(const nibble_t& input);

        /**
         * @brief Checks if hex prefixed path is for terminating leaf node
         * 
         * @param input Nibble
         * @return true if hex prefixed path is for terminating leaf node
         * @return false if hex prefixed path is not for terminating leaf node
         */
        bool IsTerminator(const nibble_t& input);

    }
}

#endif
