#ifndef IO_UTILS_H
#define IO_UTILS_H

#include <string>
#include <vector>
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

// Function to write sequences to a FASTA file
void write_fasta(const std::string& filename, const std::vector<std::string>& sequences) {
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Error: Could not open file " << filename << " for writing!" << std::endl;
        exit(1);
    }

    for (size_t i = 0; i < sequences.size(); ++i) {
        ofs << ">Sequence_" << i + 1 << "\n";
        ofs << sequences[i] << "\n";
    }

    ofs.close();
}

#endif // IO_UTILS_H
