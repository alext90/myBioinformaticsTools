#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include "fasta_parser.h" // Include your fasta_parser header

// Function to run a simple test for the fasta_parser
void test_parse_fasta() {
    // Create a temporary FASTA file for testing
    {
        std::ofstream file("data/test.fasta");
        file << ">seq1\n"
             << "GATTACA\n"
             << ">seq2\n"
             << "GCATGCU\n";
        file.close();
    }

    // Call the parser
    std::vector<std::string> sequences = parse_fasta("data/test.fasta");

    // Check the number of sequences parsed
    assert(sequences.size() == 2 && "Test failed: Expected 2 sequences");

    // Check the content of the sequences
    assert(sequences[0] == "GATTACA" && "Test failed: Expected 'GATTACA'");
    assert(sequences[1] == "GCATGCU" && "Test failed: Expected 'GCATGCU'");

    std::cout << "test_parse_fasta passed!" << std::endl;

    // Clean up the test file
    std::remove("test.fasta");
}

void test_handle_missing_file() {
    try {
        parse_fasta("non_existent_file.fasta");
        assert(false && "Test failed: Expected an exception for a missing file");
    } catch (const std::runtime_error&) {
        std::cout << "test_handle_missing_file passed!" << std::endl;
    }
}

void test_handle_empty_file() {
    // Create an empty FASTA file
    {
        std::ofstream file("empty.fasta");
        file.close();
    }

    std::vector<std::string> sequences = parse_fasta("empty.fasta");
    assert(sequences.size() == 0 && "Test failed: Expected 0 sequences in empty file");

    std::cout << "test_handle_empty_file passed!" << std::endl;

    // Clean up the empty test file
    std::remove("empty.fasta");
}

int main() {
    // Run tests
    test_parse_fasta();
    test_handle_missing_file();
    test_handle_empty_file();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
