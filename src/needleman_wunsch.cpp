#include "needleman_wunsch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream> // Include fstream for file operations

// Function to perform the Needleman-Wunsch algorithm
void needleman_wunsch(const std::string& seq1, const std::string& seq2, int match, int mismatch, int gap, const std::string& output_file) {
    int len1 = seq1.size();
    int len2 = seq2.size();
    
    // Create scoring matrix
    std::vector<std::vector<int>> score(len1 + 1, std::vector<int>(len2 + 1, 0));

    // Initialize the scoring matrix
    for (int i = 0; i <= len1; ++i) {
        score[i][0] = i * gap; // Gap penalties for seq1
    }
    for (int j = 0; j <= len2; ++j) {
        score[0][j] = j * gap; // Gap penalties for seq2
    }

    // Fill the scoring matrix
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            int match_score = (seq1[i - 1] == seq2[j - 1]) ? match : mismatch;
            score[i][j] = std::max({
                score[i - 1][j - 1] + match_score, // Diagonal (match/mismatch)
                score[i - 1][j] + gap,             // Up (gap in seq2)
                score[i][j - 1] + gap               // Left (gap in seq1)
            });
        }
    }

    // The alignment score is in the bottom-right cell of the matrix
    int alignment_score = score[len1][len2];

    // Print the alignment score
    std::cout << "Alignment Score: " << alignment_score << std::endl;

    // Traceback to find the optimal alignment
    std::string aligned_seq1, aligned_seq2;
    int i = len1, j = len2;

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && (score[i][j] == score[i - 1][j - 1] + ((seq1[i - 1] == seq2[j - 1]) ? match : mismatch))) {
            aligned_seq1 += seq1[i - 1];
            aligned_seq2 += seq2[j - 1];
            --i; --j;
        } else if (i > 0 && score[i][j] == score[i - 1][j] + gap) {
            aligned_seq1 += seq1[i - 1];
            aligned_seq2 += '-'; // Gap in seq2
            --i;
        } else {
            aligned_seq1 += '-'; // Gap in seq1
            aligned_seq2 += seq2[j - 1];
            --j;
        }
    }

    // Reverse the aligned sequences
    std::reverse(aligned_seq1.begin(), aligned_seq1.end());
    std::reverse(aligned_seq2.begin(), aligned_seq2.end());

    // Print the aligned sequences
    std::cout << "Aligned Sequence 1: " << aligned_seq1 << std::endl;
    std::cout << "Aligned Sequence 2: " << aligned_seq2 << std::endl;

    // Write the aligned sequences to a new FASTA file
    std::ofstream outfile(output_file);
    if (outfile.is_open()) {
        outfile << ">Aligned_Sequence_1\n" << aligned_seq1 << "\n";
        outfile << ">Aligned_Sequence_2\n" << aligned_seq2 << "\n";
        outfile.close();
        std::cout << "Aligned sequences written to " << output_file << std::endl;
    } else {
        std::cerr << "Error: Unable to open file for writing." << std::endl;
    }
}
