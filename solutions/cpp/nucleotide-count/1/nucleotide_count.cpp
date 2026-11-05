#include "nucleotide_count.h"
#include <map>
#include <stdexcept>
#include <string>

namespace nucleotide_count {

// TODO: add your solution here
    std::map<char, int> count(std::string seq) {
        std::map<char, int> count_map = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
        for (const auto& element : seq) {
            switch (element) {
                case 'A':
                case 'C':
                case 'G':
                case 'T':
                    count_map[element]++;
                    continue;
                default:
                    throw std::invalid_argument("Sequence contains non nucleotide elements.");
            };
        }
        return count_map;
    }
}  // namespace nucleotide_count
