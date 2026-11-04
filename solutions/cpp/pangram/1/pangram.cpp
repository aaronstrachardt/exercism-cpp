#include "pangram.h"
#include <string>
#include <array>
#include <cctype>

namespace pangram {

// TODO: add your solution here
    bool is_pangram(const std::string& sentence) {
        int count{0};
        std::array<bool, 26> seen{};
        for(size_t i{0}; i < sentence.size(); i++) {
            char lower = std::tolower(sentence.at(i));
            if (!(lower - 'a' >= 0 && lower - 'a' <= 25)) {
                continue;
            }
            if (!seen.at(lower - 'a')) {
                seen.at(lower - 'a') = true;
                count++;
            }
        }
        if (count == 26) {
            return true;
        }
        return false;
    }
}  // namespace pangram
