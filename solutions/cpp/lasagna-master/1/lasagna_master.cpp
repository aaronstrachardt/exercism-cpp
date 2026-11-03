#include "lasagna_master.h"
#include <string>
#include <vector>

namespace lasagna_master {

// TODO: add your solution here
int preparationTime(std::vector<std::string> layers, int time_per_layer) {
    return layers.size() * time_per_layer;
}

amount quantities(std::vector<std::string> layers) {
    amount needed{0,0};
    for (size_t i{0}; i < layers.size(); i++) {
        if (layers.at(i) == "noodles") {
            needed.noodles += 50;
        } else if (layers.at(i) == "sauce") {
            needed.sauce += 0.2;
        }
    }
    return needed;
}

void addSecretIngredient(std::vector<std::string>& my_list, const std::vector<std::string> friends_list) {
    std::string secretIngredient{friends_list.back()};
    my_list.pop_back();
    my_list.push_back(secretIngredient);
}

void addSecretIngredient(std::vector<std::string>& my_list, std::string enigma) {
    my_list.pop_back();
    my_list.push_back(enigma);
}

std::vector<double> scaleRecipe(const std::vector<double> quantities, int num_portions) {
    std::vector<double> new_quantities{quantities};
    for (double& quantity : new_quantities) {
        quantity *= num_portions / 2.0; 
    }
    return new_quantities;
}


}  // namespace lasagna_master
