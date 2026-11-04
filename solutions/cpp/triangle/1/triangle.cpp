#include "triangle.h"
#include <stdexcept>

namespace triangle {

// TODO: add your solution here

    bool is_triangle(double a, double b, double c) {
        if (a <= 0 || b <= 0 || c <= 0) {
            return false;
        }
        if ((a + b) >= c && (a + c) >= b && (b + c) >= a) {
            return true;
        }
        return false;
    }

    flavor kind(double a, double b, double c) {
        if (is_triangle(a, b, c)) {
            if (a == b && a == c && b == c) {
                return flavor::equilateral;
            } else if (a == b || a == c || b == c) {
                return flavor::isosceles;
            }
            return flavor::scalene;
        } else {
            throw std::domain_error("No valid triangle provided.");
        }
    }

}  // namespace triangle
