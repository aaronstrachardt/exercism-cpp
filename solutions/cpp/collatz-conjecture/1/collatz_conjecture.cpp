#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

// TODO: add your solution here
    int steps(int x) {
        if (x <= 0) {
            throw std::domain_error("Provided number smaller or equal to zero.");
        }
        int count{0};
        while (x > 1) {
            if (x % 2 == 0) {
                x /= 2;
            } else if (x % 2 == 1) {
                x = (x * 3) + 1;
            }
            count++;
        }
        return count;
    }
}  // namespace collatz_conjecture
