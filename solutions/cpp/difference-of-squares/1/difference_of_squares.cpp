#include "difference_of_squares.h"

namespace difference_of_squares {

// TODO: add your solution here
int sum_of_squares(int x) {
    int result{0}; 
    for (int i{1}; i <= x; i++) {
        result += (i * i);
    }
    return result;
}

int square_of_sum(int x) {
    int result{0};
    for (int i{1}; i <= x; i++) {
        result += i;
    }
    return result * result;
}

int difference(int x) {
    int a{square_of_sum(x)};
    int b{sum_of_squares(x)};
    return a - b;
}

}  // namespace difference_of_squares
