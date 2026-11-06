#include "sieve.h"
#include <vector>
#include <algorithm>

namespace sieve {

// TODO: add your solution here
    std::vector<int> primes(int n) {
        std::vector<int> numbers;
        for (int i = 2; i <= n; ++i) {
            numbers.push_back(i);
        }
        for (std::size_t i = 0; i < numbers.size(); ++i) {
            const int prime = numbers[i];
            for (int multiple = prime + prime; multiple <= n; multiple += prime) {
                auto it = std::lower_bound(numbers.begin(), numbers.end(), multiple);
                if (it != numbers.end() && *it == multiple) {
                    numbers.erase(it);
                }
            }
        }
        return numbers;
    }
}  // namespace sieve
