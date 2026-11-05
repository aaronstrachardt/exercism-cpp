#include "queen_attack.h"
#include <stdexcept>

namespace queen_attack {

    chess_board::chess_board(std::pair<int, int> new_white, std::pair<int, int> new_black) {
        if (new_white.first < 0 || new_white.second < 0) {
            throw std::domain_error("No negative positions allowed (white).");
        }
        if (new_white.first > 7 || new_white.second > 7) {
            throw std::domain_error("Position is out of the board (white).");
        }
        if (new_black.first < 0 || new_black.second < 0) {
            throw std::domain_error("No negative positions allowed (black).");
        }
        if (new_black.first > 7 || new_black.second > 7) {
            throw std::domain_error("Position is out of the board (black).");
        }
        if (new_white.first == new_black.first && new_white.second == new_black.second) {
            throw std::domain_error("Positions can't be equal.");
        }

        white_ = new_white;
        black_ = new_black;
    }

    std::pair<int, int> chess_board::white() const {
       return white_; 
    }

    std::pair<int, int> chess_board::black() const {
        return black_; 
    }

    bool chess_board::can_attack() const {
        if (white_.first == black_.first || white_.second == black_.second) {
            return true;
        }
        for (int i{1}; i <= 7; i++) {
            if (white_.first + i == black_.first && white_.second + i == black_.second) {
                return true;
            } else if (white_.first - i == black_.first && white_.second - i == black_.second) {
                return true;
            } else if (white_.first - i == black_.first && white_.second + i == black_.second) {
                return true;
            } else if (white_.first + i == black_.first && white_.second - i == black_.second) {
                return true;
            }
        }
        return false;
    }

}  // namespace queen_attack
