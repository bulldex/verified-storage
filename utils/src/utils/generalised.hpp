#ifndef UTILS_GENERALISED_H
#define UTILS_GENERALISED_H

// #include <sstream>
// #include <iomanip>

#include <constants/alias.hpp>
#include <constants/macros.hpp>
#include <constants/enums.hpp>

template<typename T>
bool IsNonValue(T input) {
    bool status = false;
    if(input == NULL) {
        status = true;
    } else if (input.which() == BUFFER) {
        status = input.empty();
    } else if (input.which() == BUFFERARRAY) {
        status = input.empty();
    } else if (input.which() == STRING) {
        status = input.empty();
    } else if (input.which() == LONG) {
        status = (input <= 0);
    } else if (input.which() == UNINT64) {
        status = (input <= 0);
    } else {
        // Todo check if it is an array / pointer
    }
    
    return status;
}

template<typename T>
std::vector<T> Slice(const std::vector<T>& vect, std::size_t start, std::size_t end) {
    if(end = -1) {
       end = vect.size() - 1;
    }

    auto first_ = vect.begin() + start;
    auto last_ = vect.begin() + end + 1;
    std::vector<T> sliced_vector_(first_, last_);

    return sliced_vector_;
}

template<typename T>
int GetLength(const T& input) {
    if (!input || input.size() == 0) {
        return EMPTY_STRING;
    }

    const buffer_t input_byte_ = ToBytes(input);
    const auto first_byte_ = input_byte_[0];

    int result = 0;

    if(first_byte_ <= SHORT_STRING) {
        result = input_byte_.size();
    } else if(first_byte_ <= LONG_STRING) {
        result = first_byte_ - SHORT_STRING;
    } else if(first_byte_ <= SHORT_LIST) {
        result = first_byte_ - 0xb6;
    } else if(first_byte_ <= 0xf7) {
        // a list between 0-55 bytes long
        result = first_byte_ - SHORT_LIST;
    } else {
        // a list over 55 bytes long
        const uint64_t l_length_ = first_byte_ - LONG_LIST;

        buffer_t part_byte_ = Slice(input_byte_, 1, l_length_);

        std::string part_string_ = BytesToString(part_byte_);
    
        const uint64_t length = SafeParseInt(part_string_, 16); 

        result = l_length_ + length;
    }

    return result;
}

template<typename Base, typename T>
inline bool instanceof(const T*) {
   return std::is_base_of<Base, T>::value;
}

template <typename T>
std::string GetBytes(T input) {
    // std::stringstream stream_;
    // stream_ << "<Bytes";
    // for(std::size_t i = 0; i < input.size(); i++ ) {
    //     stream_ << " " << input[i];
    // }

    // stream_ << ">";

    // return stream_.str();

    std::string byte_str_ {"<Bytes"};
    for(std::size_t i = 0; i < input.size(); i++ ) {
        uint64_t byte_ = input[i];
        byte_str_ += " " + IntegerToHex(byte_);
    }

    return byte_str_ + ">";
}

#endif
