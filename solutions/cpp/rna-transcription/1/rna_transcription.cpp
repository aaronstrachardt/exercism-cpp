#include "rna_transcription.h"
#include <stdexcept>
#include <string>

namespace rna_transcription {

// TODO: add your solution here
    char to_rna(char nuc) {
        switch (nuc) {
            case 'A':
                nuc = 'U';
                break;
            case 'C':
                nuc = 'G';
                break;
            case 'G':
                nuc = 'C';
                break;
            case 'T':
                nuc = 'A';
                break;
            default:
                throw std::invalid_argument("Nucleotide is invalid.");

        };
        return nuc;
    }

    std::string to_rna(std::string sequence) {
        for (size_t i{0}; i < sequence.length(); i++) {
            sequence.at(i) = to_rna(sequence.at(i));
        }
        return sequence;
    }
}  // namespace rna_transcription
