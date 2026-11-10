#include "prime_factors.h"
#include <vector>

namespace prime_factors {

std::vector<long long> of(long long x) {
    std::vector<long long> factors{};
    int d{2};
    while (d * d <= x) {
        while (x % d == 0) {
            factors.push_back(d);
            x /= d;
        }
        d += 1;
    }
    if (x > 1) {
        factors.push_back(x);
    }
    return factors;
}

}  // namespace prime_factors
