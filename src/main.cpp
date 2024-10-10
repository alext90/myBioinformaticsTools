#include <iostream>
#include <string>
#include "alignment.h"
#include "fasta_parser.h"

int main(int argc, char* argv[]) {
    // Check if a file path has been provided
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <fasta_file_path> <output_fasta_file>" << std::endl;
        return 1;
    }

    // Read the FASTA file path from command line
    std::string fasta_file_path = argv[1];
    std::string output_file = argv[2];
    
    std::vector<std::string> sequences = parse_fasta(fasta_file_path);

    if (sequences.size() < 2) {
        std::cerr << "Error: Less than 2 sequences found in the FASTA file!" << std::endl;
        return 1;
    }

    std::string seq1 = sequences[0];
    std::string seq2 = sequences[1];

    int match = 1;
    int mismatch = -1;
    int gap = -2;

    auto [aligned_seq1_nw, aligned_seq2_nw, score_nw] = needleman_wunsch(seq1, seq2, match, mismatch, gap);
    std::cout << "Needleman-Wunsch Alignment:\n";
    std::cout << "Alignment Score: " << score_nw << std::endl;
    print_alignment(aligned_seq1_nw, aligned_seq2_nw);

    auto [aligned_seq1_sw, aligned_seq2_sw, score_sw] = smith_waterman(seq1, seq2, match, mismatch, gap);
    std::cout << "\nSmith-Waterman Alignment:\n";
    std::cout << "Alignment Score: " << score_sw << std::endl;
    print_alignment(aligned_seq1_sw, aligned_seq2_sw);

    return 0;
}
