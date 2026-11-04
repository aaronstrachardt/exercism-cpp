#include "grains.h"
#include <cmath>

namespace grains {

// TODO: add your solution here
    unsigned long long square(int square) {
        return std::pow(2, square - 1);
    }

    unsigned long long total() {
        unsigned long long result{0};
        for (int i{1}; i <= 64; i++) {
            result += square(i);
        }
        return result;
    }
}  // namespace grains
