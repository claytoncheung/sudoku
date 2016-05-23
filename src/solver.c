#include <stdlib.h>
#include <stdio.h>
#include "solver.h"

int sudoku_helper(int puzzle[][9], int row, int column) {
  int next_num = 1;
  
  if(row == 9) {
      return 1;
  }
  if (puzzle[row][column])  {
    if (column == 8) {
      if (sudoku_helper(puzzle, row+1, 0)) {
         return 1;
       }
    } else {
      if (sudoku_helper(puzzle, row, column+1))  {
         return 1;
      }
    }
    return 0;
  }
  /*
   * Iterate through the possible numbers for this empty cell
   * and recurse for every valid one, to test if it's part
   * of the valid solution.
   */
  for (; next_num < 10; next_num++) {
    if (is_valid(next_num, puzzle, row, column)) {
      puzzle[row][column] = next_num;
     
      if (column == 8) {
        if (sudoku_helper(puzzle, row+1, 0)) {
         return 1;
        }
      }  else {
        if (sudoku_helper(puzzle, row, column+1)) {
          return 1;
        } 
      }
      // Failed to find a valid value for this 
      puzzle[row][column] = 0;
    }
  }
  return EXIT_SUCCESS;
}

//Checks if a value is valid in the specified position
int is_valid(int number, int puzzle[][9], int row, int column) {
  int i = 0;
  int sector_row = 3*(row/3);
  int sector_col = 3*(column/3);
  int row1 = (row + 2)%3;
  int row2 = (row + 4)%3;
  int col1 = (column + 2)%3;
  int col2 = (column + 4)%3;
  
  //Check for the value in the given row and column
  for(i = 0; i < 9; i ++) {
    if (puzzle[i][column] == number) {
      return 0;
    }
    if (puzzle[row][i] == number) {
      return 0;
    }
  }
  if(puzzle[row1+sector_row][col1+sector_col] == number) {
    return 0;
  }
  if(puzzle[row2+sector_row][col1+sector_col] == number) {
    return 0;
  }
  if(puzzle[row1+sector_row][col2+sector_col] == number) {
    return 0;
  }
  if(puzzle[row2+sector_row][col2+sector_col] == number) {
    return 0;
  }
  return 1;
}
