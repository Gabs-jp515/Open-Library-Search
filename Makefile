# Compiler and flags
CC = gcc
CFLAGS = -Wall
LDFLAGS = -lcjson -lcurl

# Source files
SRC = fetch_data.c json_parser.c
OBJ = $(SRC:.c=.o)
TARGET = book_search

# Default target
$(TARGET): $(OBJ)
	@echo ":: Linking ::"
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Rule to compile each .c file into .o
%.o: %.c
	@echo ":: Compiling $< ::"
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo ":: Cleaning ::"
	rm -f $(OBJ) $(TARGET)

