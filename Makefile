# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Default target
.PHONY: all clean

# Compile file.c into file.out
%.c:
	$(CC) $< -o file.out

# Clean up generated files
clean:
	rm -f *.out
