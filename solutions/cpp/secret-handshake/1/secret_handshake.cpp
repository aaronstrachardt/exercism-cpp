#include "secret_handshake.h"
#include <algorithm>
#include <bitset>
#include <cstddef>
#include <string>
#include <vector>

namespace secret_handshake {
// TODO: add your solution here
std::vector<std::string> commands(int x) {
    std::bitset<5> secret(x);
    std::string s_secret = secret.to_string();
    std::vector<std::string> actions{};

    
    std::reverse(s_secret.begin(), s_secret.end());

    for (size_t i{0}; i < s_secret.length(); i++) {
        switch (i) {
            case 0:
                if (s_secret.at(0) == '1') {
                    actions.push_back("wink");
                }
                break;
            case 1:
                if (s_secret.at(1) == '1') {
                    actions.push_back("double blink");
                } 
                break;
            case 2:
                if (s_secret.at(2) == '1') {
                    actions.push_back("close your eyes");
                }
                break;
            case 3:
                if (s_secret.at(3) == '1') {
                    actions.push_back("jump");
                }
                break;
            case 4:
                if (s_secret.at(4) == '1') {
                    std::reverse(actions.begin(), actions.end());
                }
                break;
            default:
                break;
    }

    }
    return actions;
    }  // namespace secret_handshake
}