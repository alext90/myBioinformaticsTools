# My Bioinformatics Tools

A collection of bioinformatics tools written in C++.  
Mainly a project for me to practice C++ and learn some Bioinformatics.

#### Methods:
- Needleman-Wunsch alignment
- Smith-Waterman alignment


#### Statistics
- Identity percentage
- Gap percentage
- Mutation frequency
- Alignment coverage
- Hamming distance
- Num gaps
- Longest continous match


#### Run
```
make
./build/alignment_program data/example.fasta data/aligned.fasta
```

#### Sample Output
```
Needleman-Wunsch Alignment:
Alignment Score: 128
Identity Percentage: 87.0968%
Gap Percentage: 5.37634%
Number of Gaps: 10
Longest Contiguous Match: 31
Mutation Frequency: 7.52688%
Alignment Coverage: 100%

Smith-Waterman Alignment:
Alignment Score: 144
Identity Percentage: 91.0112%
Gap Percentage: 1.1236%
Number of Gaps: 2
Longest Contiguous Match: 31
Mutation Frequency: 7.86517%
Alignment Coverage: 100%
```