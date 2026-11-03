#pragma once
#include <vector>
#include <string>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(std::vector<std::string> layers, int time_per_layer = 2);
amount quantities(std::vector<std::string> layers);
void addSecretIngredient(std::vector<std::string>& my_list, const std::vector<std::string> friends_list);
void addSecretIngredient(std::vector<std::string>& my_list, std::string enigma);
std::vector<double> scaleRecipe(const std::vector<double> quantities, int num_portions);

}  // namespace lasagna_master
