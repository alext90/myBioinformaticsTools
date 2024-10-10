#ifndef NEEDLEMAN_WUNSCH_H
#define NEEDLEMAN_WUNSCH_H

#include <string>

void needleman_wunsch(const std::string& seq1, const std::string& seq2, int match, int mismatch, int gap, const std::string& output_file);

#endif // NEEDLEMAN_WUNSCH_H
