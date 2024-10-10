#ifndef STATS_H
#define STATS_H

#include <iostream>
#include <string>

// Function to calculate the identity percentage between two aligned sequences
double calculate_identity(const std::string& aligned_seq1, const std::string& aligned_seq2) {
    int matches = 0;
    int total_positions = aligned_seq1.length();
    
    // Ensure both sequences are of the same length
    if (aligned_seq1.length() != aligned_seq2.length()) {
        std::cerr << "Error: Sequences must be of the same length!" << std::endl;
        return -1;
    }

    for (int i = 0; i < total_positions; ++i) {
        // Count only non-gap matches
        if (aligned_seq1[i] != '-' && aligned_seq2[i] != '-' && aligned_seq1[i] == aligned_seq2[i]) {
            matches++;
        }
    }

    return (static_cast<double>(matches) / total_positions) * 100;
}

// Function to calculate the gap percentage between two aligned sequences
double calculate_gap_percentage(const std::string& aligned_seq1, const std::string& aligned_seq2) {
    int gaps = 0;
    int total_positions = aligned_seq1.length();
    
    // Ensure both sequences are of the same length
    if (aligned_seq1.length() != aligned_seq2.length()) {
        std::cerr << "Error: Sequences must be of the same length!" << std::endl;
        return -1;
    }

    for (int i = 0; i < total_positions; ++i) {
        // Count positions where there is a gap ('-') in either sequence
        if (aligned_seq1[i] == '-' || aligned_seq2[i] == '-') {
            gaps++;
        }
    }

    return (static_cast<double>(gaps) / total_positions) * 100;
}

#endif // STATS_H