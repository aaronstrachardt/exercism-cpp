#include "two_fer.h"
#include <string>

namespace two_fer {

// TODO: add your solution here
    std::string two_fer() {
        return "One for you, one for me.";
    }
    std::string two_fer(const std::string& name) {
        return "One for " + name + ", one for me.";
    }
}  // namespace two_fer
