#include "nth_prime.h"
#include <cmath>
#include <stdexcept>

namespace nth_prime {

bool is_prime(int n) {
    for (int i{3}; i <= std::sqrt(n); i = i + 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;

}

// TODO: add your solution here
int nth(int n) {
    if (n == 0) {
        throw std::domain_error("There is no 0th prime number.");
    }
    if (n == 1) {
        return 2;
    }
    int counter{1};
    int potential_prime{3};
    while (n != counter) {
        if (is_prime(potential_prime)) {
            counter++;
        }
        potential_prime = potential_prime + 2;
    }
    return potential_prime - 2;
}

}  // namespace nth_prime
