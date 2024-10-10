CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.cpp src/needleman_wunsch.cpp src/fasta_parser.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = needleman_wunsch

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
