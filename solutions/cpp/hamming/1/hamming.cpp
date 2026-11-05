#include "hamming.h"
#include <stdexcept>
#include <string>

namespace hamming {

// TODO: add your solution here
    int compute(std::string dna1, std::string dna2) {
        int hamming_distance{0};

        if (dna1.length() != dna2.length()) {
            throw std::domain_error("Hamming distance is only defined for equal length sequences.");
        }

        for (size_t i{0}; i < dna1.length(); i++) {
            if (dna1.at(i) != dna2.at(i)) {
                hamming_distance++;
            }
        }
        
        return hamming_distance;
    }
}  // namespace hamming
