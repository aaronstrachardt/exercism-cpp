#include "reverse_string.h"

namespace reverse_string {

// TODO: add your solution here
    std::string reverse_string(std::string str) {
        std::string result{""};
        size_t init_len{str.length()};
        for(size_t i{0}; i < init_len; i++) {
            result += str.back();
            str.pop_back();
        }
        return result;
    }
}  // namespace reverse_string
