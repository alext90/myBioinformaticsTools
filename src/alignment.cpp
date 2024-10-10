// alignment.cpp
#include "alignment.h"
#include "stats.h"
#include <iostream>
#include <vector>
#include <algorithm>

// Implement Needleman-Wunsch algorithm
std::pair<std::string, std::string> needleman_wunsch(const std::string& seq1, const std::string& seq2, int match, int mismatch, int gap) {
    int n = seq1.length();
    int m = seq2.length();

    // Create the score matrix
    std::vector<std::vector<int>> score(n + 1, std::vector<int>(m + 1, 0));

    // Initialize the score matrix
    for (int i = 0; i <= n; ++i) {
        score[i][0] = i * gap;
    }
    for (int j = 0; j <= m; ++j) {
        score[0][j] = j * gap;
    }

    // Fill the score matrix
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int match_tmp = score[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? match : mismatch);
            int delete_op = score[i - 1][j] + gap;
            int insert_op = score[i][j - 1] + gap;
            score[i][j] = std::max({match_tmp, delete_op, insert_op});
        }
    }

    // Traceback to find the aligned sequences
    std::string aligned_seq1;
    std::string aligned_seq2;
    int i = n;
    int j = m;

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && (score[i][j] == score[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? match : mismatch))) {
            aligned_seq1 += seq1[i - 1];
            aligned_seq2 += seq2[j - 1];
            --i;
            --j;
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
    std::cout << "Alignment Score: " << score[n][m] << std::endl;

    return {aligned_seq1, aligned_seq2};
}

// Implement Smith-Waterman algorithm
std::pair<std::string, std::string> smith_waterman(const std::string& seq1, const std::string& seq2, int match, int mismatch, int gap) {
    int n = seq1.length();
    int m = seq2.length();

    // Create the score matrix
    std::vector<std::vector<int>> score(n + 1, std::vector<int>(m + 1, 0));

    // Fill the score matrix
    int max_score = 0;
    int max_i = 0, max_j = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int match_tmp = score[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? match : mismatch);
            int delete_op = score[i - 1][j] + gap;
            int insert_op = score[i][j - 1] + gap;

            // Take the maximum of the three options and zero
            score[i][j] = std::max({0, match_tmp, delete_op, insert_op});

            // Update max score and its position
            if (score[i][j] > max_score) {
                max_score = score[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    // Traceback to find the aligned sequences
    std::string aligned_seq1;
    std::string aligned_seq2;

    int i = max_i;
    int j = max_j;

    while (score[i][j] != 0) {
        if (i > 0 && j > 0 && (score[i][j] == score[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? match : mismatch))) {
            aligned_seq1 += seq1[i - 1];
            aligned_seq2 += seq2[j - 1];
            --i;
            --j;
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
    std::cout << "Alignment Score: " << score[n][m] << std::endl;

    return {aligned_seq1, aligned_seq2};
}

// Utility function to print aligned sequences
void print_alignment(const std::string& aligned_seq1, const std::string& aligned_seq2) {
    std::cout << "Alignment:\n" << aligned_seq1 << "\n" << aligned_seq2 << std::endl;
}
