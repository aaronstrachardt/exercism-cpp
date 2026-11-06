#include "say.h"
#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

namespace say {

std::vector<std::string> word_list{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

std::vector<std::string> tens{"None", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

bool range_check(int n) {
    return n > 3 && n <= 9; 
}

std::string build_tens(int first, int second) {
    if (second == 0 && first != 0) {
        return tens.at(first);
    }
    return tens.at(first) + "-" + word_list.at(second);
}

std::string build_hundred(std::string group) {;
    int word = group.at(0) - '0';
    int first = group.at(1) - '0';
    int second = group.at(2) - '0';

    if (std::stoi(group.substr(1, 2)) == 00) {
        
        return word_list.at(word) + " hundred";
    }

    if (std::stoi(group.substr(1, 2)) <= 20) {
        
        return word_list.at(word) + " hundred " + word_list.at(std::stoi(group.substr(1, 2)));
    }
    return word_list.at(word) + " hundred " + build_tens(first, second);
}

std::string build_logic(int x) {
    if (x <= 20) {
        return word_list.at(x);
    }
    if (x <= 99) {
        std::string digits = std::to_string(x);
        int first = digits.at(0) - '0';
        int second = digits.at(1) - '0';
        return build_tens(first, second);
    }
    return build_hundred(std::to_string(x));
}

// TODO: add your solution here
std::string in_english(long long x) {
    if (x < 0 || x > 999999999999) {
        throw std::domain_error("Out of range.");
    }

    if (x <= 20) {
        return word_list.at(x);
    }
    
    std::vector<std::string> result{};

    std::string num_as_string = std::to_string(x);
    std::vector<int> parts{};
    std::reverse(num_as_string.begin(), num_as_string.end());

    for (size_t i = 0; i < num_as_string.size(); i += 3) {
        std::string chunk = num_as_string.substr(i, 3);
        std::reverse(chunk.begin(), chunk.end());
        parts.push_back(std::stoi(chunk));
    }

    for (size_t i{0}; i < parts.size(); i++) {
        if (parts.at(i) == 0) {
            continue;
        }
        if (i == 0) {
            result.push_back(build_logic(parts.at(0)));
        } else if (i == 1) {
            result.push_back(build_logic(parts.at(1)) + " thousand ");
        } else if (i == 2) {
            result.push_back(build_logic(parts.at(2)) + " million ");
        } else if (i == 3) {
            result.push_back(build_logic(parts.at(3)) + " billion ");
        }
    }
    std::reverse(result.begin(),result.end());
    std::string solution{""};
    for (const auto& element : result) {
        solution += element;
    }
    if (solution.back() == ' ') {
        solution.pop_back();
    }
    return solution;

}

}  // namespace say
