#include <iostream>
#include <string>

class Statistics {
private:
    std::string _seq1;
    std::string _seq2;
    
    double identity_percentage;
    double gap_percentage;
    double mutation_frequency;
    double alignment_coverage;
    double hamming_distance;

    int num_gaps;
    int longest_continous_match;

    void calculate_statistics() {
        int total_positions = _seq1.length();
        
        int mutations = 0;
        int _positions = 0;

        int longest_match = 0;
        int current_match = 0;        

        int gaps = 0;
        int matches = 0;
        int mismatches = 0;

        for (int i = 0; i < total_positions; ++i) {
            // matches
            if (seq1[i] != '-' && _seq2[i] != '-' && _seq1[i] == _seq2[i]) {
                matches++;
            }
            if (seq1[i] != '-' && seq2[i] != '-' && seq1[i] != seq2[i]) {
                mismatches++;
            }

            // Count only non-gap mismatches
            if (_seq1[i] != '-' && _seq2[i] != '-' && _seq1[i] != _seq2[i]) {
                mutations++;
            }

            // correct alignments
            if (_seq1[i] != '-' || _seq2[i] != '-') {
                _positions++;
            }

            // count longest match
            if (_seq1[i] != '-' && _seq2[i] != '-' && _seq1[i] == _seq2[i]) {
                current_match++;
            } else {
                if (current_match > longest_match) {
                    longest_match = current_match;
                }
                current_match = 0;
            }

            // count gaps
            if (_seq1[i] == '-' || _seq2[i] == '-') {
                gaps++;
            }
        }

        identity_percentage = (static_cast<double>(matches) / total_positions) * 100;
        hamming_distance = (static_cast<double>(mismatches) / total_positions) * 100;
        mutation_frequency = (static_cast<double>(mutations) / total_positions) * 100;
        alignment_coverage = (static_cast<double>(_positions) / total_positions) * 100;
        longest_continous_match = longest_match;
        num_gaps = gaps;
        gap_percentage = (static_cast<double>(gaps) / total_positions) * 100;
    }



public:
    // Constructor that takes two  sequences and computes statistics
    Statistics(const std::string& seq1, const std::string& seq2)
        : _seq1(seq1), _seq2(seq2) {
        
        // Check if the sequences are of the same length
        if (_seq1.length() != _seq2.length()) {
            std::cerr << "Error: Sequences must be of the same length!" << std::endl;
            return;
        }

        // Calculate statistics
        calculate_statistics();    
    }

    // Getter methods for statistics
    double get_identity_percentage() const {
        return identity_percentage;
    }

    double get_gap_percentage() const {
        return gap_percentage;
    }

    double get_mutation_frequency() const {
        return mutation_frequency;
    }

    double get_alignment_coverage() const {
        return alignment_coverage;
    }

    int get_number_gaps() const {
        return num_gaps;
    }

    int get_longest_continous_match() const {
        return longest_continous_match;
    }

    // Print method to display statistics
    void print_statistics() const {
        std::cout << "Identity Percentage: " << identity_percentage << "%" << std::endl;
        std::cout << "Hamming Distance: " << hamming_distance << "%" << std::endl;
        std::cout << "Gap Percentage: " << gap_percentage << "%" << std::endl;
        std::cout << "Number of Gaps: " << num_gaps << std::endl;
        std::cout << "Longest Contiguous Match: " << longest_continous_match << std::endl;
        std::cout << "Mutation Frequency: " << mutation_frequency << "%" << std::endl;
        std::cout << "Alignment Coverage: " << alignment_coverage << "%" << std::endl;
    }
};