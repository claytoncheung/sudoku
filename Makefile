CC = clang
CFLAGS = -Wall -Wextra -std=c99 -lpthread
LFLAGS =
LIBS = -lm
SOURCES = sudoku.c solver.c validator.c
OBJECTS = $(subst .c,.o,$(SOURCES))
FILES = puzzle.txt solved_puzzle.txt
EXE = sudoku.exe
.PHONY: clean help

sudoku.exe : sudoku.o validator.o solver.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $<

all : $(EXE)

clean:
	rm -f $(OBJECTS) $(EXE) $(FILES) *~

help:
	@echo "Valid targets:"
	@echo "  clean:  removes .o, .exe, .txt files"
