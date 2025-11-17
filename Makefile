# Makefile for Twixt-C Phase 1

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Source folder
SRC_DIR = source

# Find all .c files in the source folder
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Executable name
TARGET = twixt

# Default rule: build the executable
all: $(TARGET)

# Build the executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean: remove the executable
clean:
	rm -f $(TARGET)
