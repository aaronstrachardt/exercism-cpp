#pragma once
#include <vector>
#include <string>

namespace say {

// TODO: add your solution here
bool range_check(int n);
std::string build_tens(int first, int second);
std::string build_hundred(std::string group);
std::string build_logic(int x);
std::string in_english(long long x);
}  // namespace say
