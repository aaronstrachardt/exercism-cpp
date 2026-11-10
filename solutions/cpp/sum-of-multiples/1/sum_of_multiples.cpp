#include "sum_of_multiples.h"
#include <unordered_set>
#include <vector>

namespace sum_of_multiples {

int to(std::vector<int> base_levels, int player_level) {
    std::unordered_set<int> unique_multiplies{};
    for (const auto& element : base_levels) {
        int element_to_check{element};
        while (element_to_check < player_level) {
            unique_multiplies.emplace(element_to_check);
            element_to_check += element;
        }
    }
    int result{0};
    for (const auto& element : unique_multiplies) {
        result += element;
    }

    return result;
}

}  // namespace sum_of_multiples
