#include "fasta_parser.h"
#include <fstream>
#include <iostream>

// Implementation of the FASTA parsing function
std::vector<std::string> parse_fasta(const std::string& filename) {
    std::vector<std::string> sequences;
    std::ifstream infile(filename);
    std::string line;
    std::string sequence;

    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return sequences;
    }

    while (std::getline(infile, line)) {
        if (line[0] == '>') {
            // Store the previous sequence before starting a new one
            if (!sequence.empty()) {
                sequences.push_back(sequence);
                sequence.clear();
            }
        } else {
            sequence += line; // Append the current line to the sequence
        }
    }

    // Push the last sequence
    if (!sequence.empty()) {
        sequences.push_back(sequence);
    }

    return sequences;
}
