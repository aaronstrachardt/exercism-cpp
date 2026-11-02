#include "protein_translation.h"
#include <algorithm>
#include <cstddef>
#include <vector>
#include <string>

namespace protein_translation {

// TODO: add your solution here
std::vector<std::string> proteins(std::string codon_seq) {
    std::vector<std::string> chunks{};
    std::vector<std::string> solution{};
    for (size_t i{0}; i < codon_seq.length(); i += 3) {
        chunks.push_back(codon_seq.substr(i, std::min(size_t(3), codon_seq.length() - i)));
    }
    for (size_t i{0}; i < chunks.size(); i++) {
        if (chunks.at(i) == "AUG") {
            solution.push_back("Methionine");
        } else if (chunks.at(i) == "UUU" || chunks.at(i) == "UUC") {
            solution.push_back("Phenylalanine");
        } else if (chunks.at(i) == "UUA" || chunks.at(i) == "UUG") {
            solution.push_back("Leucine");
        } else if (chunks.at(i) == "UCU" || chunks.at(i) == "UCC" || chunks.at(i) == "UCA" || chunks.at(i) == "UCG") {
            solution.push_back("Serine");
        } else if (chunks.at(i) == "UAU" || chunks.at(i) == "UAC") {
            solution.push_back("Tyrosine");
        } else if (chunks.at(i) == "UGU" || chunks.at(i) == "UGC") {
            solution.push_back("Cysteine");
        } else if (chunks.at(i) == "UGG") {
            solution.push_back("Tryptophan");
        } else if (chunks.at(i) == "UAA" || chunks.at(i) == "UAG" || chunks.at(i) == "UGA") {
            break;
        }
    }
    return solution;
}

}  // namespace protein_translation
