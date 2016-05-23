#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "validator.h"
#include "solver.h"
const char* puzzleFile = "puzzle.txt";

int main(void) {
	clock_t start = clock(), diff;
	int puzzle[9][9];
	int duplicates = 1;

	FILE *fp = fopen(puzzleFile, "r");
	//Reads the sudoku numbers from puzzle.txt
	for (int i=0;i<9;i++) {
		for (int j=0;j<9;j++) {
			fscanf(fp, "%d", &puzzle[i][j]);
		}
	}

	fclose(fp);

	sudoku_helper(puzzle, 0, 0);
	
	diff = clock() - start;
	int msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Time taken to solve: %d seconds %d milliseconds\n", msec/1000, msec%1000);

	duplicates = validateAll(puzzle);

	if (duplicates == 1) {
		printf("The puzzle is valid, there are no duplicates\n");
	} else if (duplicates == 0) {
		printf("The puzzle contains duplicates \n");
	}
	
	diff = clock() - start;
	msec = diff * 1000 / CLOCKS_PER_SEC;
	printf("Time taken to solve and validate: %d seconds %d milliseconds\n", msec/1000, msec%1000);
	
	FILE *solved = fopen("solved_puzzle.txt", "w");
	for(int i = 0; i <9; i++)	{
		for(int j = 0; j < 9; j++) {
			fprintf(solved, "%d ", puzzle[i][j]);
			printf("%d ", puzzle[i][j]);
		}
		fprintf(solved, "\n");
		printf("\n");
	}
	fclose(solved);

	return 0;
}
