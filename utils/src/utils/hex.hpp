#ifndef UTILS_HEX_H
#define UTILS_HEX_H

#include <string>
#include <stdint.h>
#include <vector>

#include <constants/alias.hpp>

namespace verified {
    namespace utils {
    
        /**
         * Generates the empty byte
         * 
         * @return buffer_t Empty byte 
         */
        buffer_t EmptyByte();

        /**
         * Check if given string is numeric or not
         * 
         * @param input string to be checked
         * @return true if the string is number
         * @return false if string is not a number
         */
        bool IsNumeric(const std::string& input);

        /**
         * @brief Is the string having hex prefix, i.e., 0x
         * 
         * @param input string to be examined
         * @return true if the hex prefix is present
         * @return false if the hex prefix does not exists
         */
        bool IsHexPrefixed(const std::string& input);

        /**
         * @brief Check if the string is hex string? 
         * 
         * @param input String to be examined
         * @return true If the string is hex string
         * @return false if the string is now hex string
         */
        bool IsHexString(const std::string& input);

        /**
         * @brief Insert Hex prefix to the hexadecimal string
         * 
         * @param input Hexadecimal string to be hex prefixed
         * @return std::string Hex prefixed heaxadecimal string
         */
        std::string InsertHexPrefix(const std::string& input);

        /**
         * @brief Remove hex prefix if it exists
         * 
         * @param input String from which hex prefix is to be removed
         * @return std::string processed string by removing hex prefix
         */
        std::string StripHexPrefix(const std::string& input);

        /**
         * @brief Add even padding to the string.
         * This will check if the string is having length even or not. 
         * If it is not even length, it will add 0 paddinf to make it even lenght.
         * 
         * @param input String to be padded with
         * @return std::string String with even padded.
         */
        std::string PadToEven(const std::string& input);

        /**
         * @brief Convert integer number of hexadecimal representaion 
         * 
         * @param input number to be converted to hex representation
         * @return std::string Hex String having representation of the input string
         */
        std::string IntegerToHex(const uint64_t input);

        /**
         * @brief Convert a hexadecimal string to human readable integer number
         * 
         * @param input hexadecimal string
         * @return uint64_t Human readable integer
         */
        uint64_t HexToInteger(const std::string& input);

        /**
         * @brief Convert a string to hexadecimal format
         * 
         * @param input string to be converted to hexadecimal format
         * @param prefix flag to indicate whether to add `0x` (hex) prefix to the hex string or not.
         * @param upper flag to indicate whether to convert hex string to uppercase. Default false
         * @return std::string String having hexadecimal representation of the input string
         */
        std::string StringToHex(const std::string& input, bool prefix=true, bool upper=false);

        /**
         * @brief Convert a hexadecimal string to human readable string
         * 
         * @param input hexadecimal string
         * @return std::string Human readable string
         */
        std::string HexToString(const std::string& input);

        /**
         * @brief Safely parse string to integer 
         * 
         * @param input string to be parsed to integer
         * @param base base at which to parse the number, i.e. 2, 3, octal, hex, etc.
         * @return std::uint64_t parsed integer number
         */
        std::uint64_t SafeParseInt(const std::string& input, unsigned int base=10);

        /**
         * @brief Convert Integer to Bytes
         * 
         * @param input Large integer to be converted to bytes
         * @return buffer_t bytes representation of the integer
         */
        buffer_t IntegerToBytes(const uint64_t input);

        /**
         * @brief Convert bytes to Integer
         * 
         * @param input bytes representation of the number
         * @return uint64_t integer number
         */
        uint64_t BytesToInteger(const buffer_t& input);

        /**
         * @brief Convert string to bytes 
         * 
         * @param input String to be converted to bytes
         * @param ishex flag to indicate whether provided string is hex or not
         * @return buffer_t bytes representation of the string
         */
        buffer_t StringToBytes(const std::string& input, const bool ishex=false);

        /**
         * @brief Convert bytes to Hex string
         * 
         * @param input Bytes to be converted in hex string
         * @return std::string Hex representation of string
         */
        std::string BytesToString(const buffer_t& input);

        /**
         * Convert String to bytes
         * 
         * @param input String to be converted to bytes
         * @return std::vector<uint64_t> Bytes representation
         */
        buffer_t ToBytes(const std::string& input);

        // std::vector<uint64_t> ArrayToBytes(const std::string input[]);

        /**
         * @brief Check if input is non value or not, i.e. input is 0 / null / nullptr // ''
         * 
         * @tparam T Type of the input
         * @param input Input to be checked 
         * @return true if it is non value
         * @return false If it is not non value
         */
        template<typename T>
        bool IsNonValue(T input);

        /**
         * @brief Get the Length object
         * 
         * @tparam T Input type
         * @param input Input value
         * @return int length
         */
        template<typename T>
        int GetLength(const T& input);

        /**
         * @brief Slice the vector from start to end
         * 
         * @tparam T Type of vector
         * @param v Vector be sliced
         * @param start Start point
         * @param end End point
         * @return std::vector<T> Sliced vector
         */
        template<typename T>
        std::vector<T> Slice(const std::vector<T>& vect, std::size_t start, std::size_t end=-1);

        /**
         * @brief Checks if the object is an instance of the Template class name
         * 
         * @tparam Base Base class
         * @tparam T Class name whose type the object needs to be checked
         * @return true if the object is instance of T
         * @return false if object is not instance of T
         */
        template<typename Base, typename T>
        inline bool instanceof(const T*);

        /**
         * @brief Get the Bytes object
         * 
         * @tparam T Vector representing bytes
         * @param input Bytes
         * @return std::string string representation of bytes 
         */
        template<typename T>
        std::string GetBytes(T input);

        #include "generalised.hpp"

}

}

#endif