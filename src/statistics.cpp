#include <iostream>
#include <string>

class Statistics {
private:
    std::string aligned_seq1;
    std::string aligned_seq2;
    double identity_percentage;
    double gap_percentage;

    // Private method to calculate identity percentage
    double calculate_identity() {
        int matches = 0;
        int total_positions = aligned_seq1.length();
        
        for (int i = 0; i < total_positions; ++i) {
            // Count only non-gap matches
            if (aligned_seq1[i] != '-' && aligned_seq2[i] != '-' && aligned_seq1[i] == aligned_seq2[i]) {
                matches++;
            }
        }

        return (static_cast<double>(matches) / total_positions) * 100;
    }

    // Private method to calculate gap percentage
    double calculate_gap_percentage() {
        int gaps = 0;
        int total_positions = aligned_seq1.length();

        for (int i = 0; i < total_positions; ++i) {
            // Count positions where there is a gap ('-') in either sequence
            if (aligned_seq1[i] == '-' || aligned_seq2[i] == '-') {
                gaps++;
            }
        }

        return (static_cast<double>(gaps) / total_positions) * 100;
    }

public:
    // Constructor that takes two aligned sequences and computes statistics
    Statistics(const std::string& seq1, const std::string& seq2)
        : aligned_seq1(seq1), aligned_seq2(seq2) {
        
        // Check if the sequences are of the same length
        if (aligned_seq1.length() != aligned_seq2.length()) {
            std::cerr << "Error: Sequences must be of the same length!" << std::endl;
            return;
        }

        // Calculate both statistics
        identity_percentage = calculate_identity();
        gap_percentage = calculate_gap_percentage();
    }

    // Getter methods for the statistics
    double get_identity_percentage() const {
        return identity_percentage;
    }

    double get_gap_percentage() const {
        return gap_percentage;
    }

    // Print method to display statistics
    void print_statistics() const {
        std::cout << "Identity Percentage: " << identity_percentage << "%" << std::endl;
        std::cout << "Gap Percentage: " << gap_percentage << "%" << std::endl;
    }
};