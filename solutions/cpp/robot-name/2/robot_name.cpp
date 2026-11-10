#include "robot_name.h"
#include <string>
#include <unordered_set>
#include <random>

namespace robot_name {

    std::unordered_set<std::string> set_of_names{};

    robot::robot() {
        std::string new_name{generate_name()};
        while (set_of_names.count(new_name) == 1) {
            new_name = generate_name();
        }
        name_ = new_name;
        set_of_names.emplace(new_name);
    }

    std::string robot::name() const {
        return name_;
    }

    void robot::reset() {
        std::string new_name{generate_name()};
        while (set_of_names.count(new_name) == 1) {
            new_name = generate_name();
        }
        name_ = new_name;
        set_of_names.emplace(new_name);
    }

    std::string generate_name() {
        std::random_device rd;
        std::mt19937 gen(rd());
        
        std::uniform_int_distribution<int> letter_dist(0, 25);
        std::uniform_int_distribution<int> digit_dist(0, 9);
    
        char l1 = 'A' + letter_dist(gen);
        char l2 = 'A' + letter_dist(gen);
        
        int d1 = digit_dist(gen);
        int d2 = digit_dist(gen);
        int d3 = digit_dist(gen);
    
        return {l1, l2, 
                static_cast<char>('0' + d1), 
                static_cast<char>('0' + d2), 
                static_cast<char>('0' + d3)};
    }

}  // namespace robot_name
