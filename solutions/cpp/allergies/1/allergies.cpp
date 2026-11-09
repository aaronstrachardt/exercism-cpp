#include "allergies.h"

namespace allergies {

allergy_test::allergy_test(int score) {
    score_ = score;
    if (score_ & 1) {
        allergies_.emplace("eggs");
    }
    if (score_ & 2) {
        allergies_.emplace("peanuts");
    }
    if (score_ & 4) {
        allergies_.emplace("shellfish");
    }
    if (score_ & 8) {
        allergies_.emplace("strawberries");
    }
    if (score_ & 16) {
        allergies_.emplace("tomatoes");
    }
    if (score_ & 32) {
        allergies_.emplace("chocolate");
    }
    if (score_ & 64) {
        allergies_.emplace("pollen");
    }
    if (score_ & 128) {
        allergies_.emplace("cats");
    }
}

bool allergy_test::is_allergic_to(const std::string& allergen) const {
    return allergies_.count(allergen) == 1;
}

std::unordered_set<std::string> allergy_test::get_allergies() const {
    return allergies_;
}

}  // namespace allergies
