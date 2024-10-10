# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
TEST_DIR = test

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executable name
EXECUTABLE = $(BUILD_DIR)/alignment_program

# Default target
all: $(EXECUTABLE)

# Build the executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)  # Create build directory if it doesn't exist
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean the build
clean:
	rm -rf $(BUILD_DIR)/*
	rm -f $(EXECUTABLE)

# Run tests
test:
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -o $(BUILD_DIR)/test_program $(TEST_DIR)/*.cpp $(OBJECTS)  # Adjust this if needed
	$(BUILD_DIR)/test_program

.PHONY: all clean test
