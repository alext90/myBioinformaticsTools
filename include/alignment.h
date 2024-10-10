// alignment.h
#ifndef ALIGNMENT_H
#define ALIGNMENT_H

#include <string>
#include <vector>

// Needleman-Wunsch algorithm
std::tuple<std::string, std::string, int> needleman_wunsch(const std::string& seq1, const std::string& seq2, int match, int mismatch, int gap);

// Smith-Waterman algorithm (function prototype for another alignment algorithm)
std::tuple<std::string, std::string, int>  smith_waterman(const std::string& seq1, const std::string& seq2, int match, int mismatch, int gap);

// Utility function to print aligned sequences
void print_alignment(const std::string& aligned_seq1, const std::string& aligned_seq2);

#endif // ALIGNMENT_H
