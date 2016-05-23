CC = clang
CFLAGS = -Wall -Wextra -std=c99 -lpthread
LIBS = -lm
SOURCES =	\
	src/sudoku.c \
	src/solver.c \
	src/validator.c
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
FILES = puzzle.txt solved_puzzle.txt
EXE = bin/sudoku.exe
.PHONY: all clean help

all : $(EXE)

$(EXE) : $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

$(OBJECTS) : src/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJECTS) $(EXE) $(FILES) *~

help:
	@echo "Valid targets:"
	@echo "  clean:  removes .o, .exe, .txt files"
