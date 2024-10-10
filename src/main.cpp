#include <iostream>
#include <string>
#include "needleman_wunsch.h"
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

    std::cout << "Running Needleman-Wunsch algorithm..." << std::endl;
    needleman_wunsch(seq1, seq2, match, mismatch, gap, output_file);

    return 0;
}
