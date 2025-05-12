# Compiler and flags
CC = gcc
CFLAGS = -Wall
LDFLAGS = -lcjson -lcurl

# Programs and their sources
DOWNLOAD_SRC = download_data.c
PARSER_SRC = json_parser.c

DOWNLOAD_OBJ = $(DOWNLOAD_SRC:.c=.o)
PARSER_OBJ = $(PARSER_SRC:.c=.o)

DOWNLOAD_EXE = fetch_data
PARSER_EXE = parse_data

# Build both targets
all: $(DOWNLOAD_EXE) $(PARSER_EXE)

$(DOWNLOAD_EXE): $(DOWNLOAD_OBJ)
	@echo ":: Linking fetch_data ::"
	$(CC) $(DOWNLOAD_OBJ) -o $(DOWNLOAD_EXE) $(LDFLAGS)

$(PARSER_EXE): $(PARSER_OBJ)
	@echo ":: Linking parse_data ::"
	$(CC) $(PARSER_OBJ) -o $(PARSER_EXE) $(LDFLAGS)

%.o: %.c
	@echo ":: Compiling $< ::"
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo ":: Cleaning ::"
	rm -f $(DOWNLOAD_OBJ) $(PARSER_OBJ) $(DOWNLOAD_EXE) $(PARSER_EXE)

