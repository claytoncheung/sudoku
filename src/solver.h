#ifndef _SOLVER_H_
#define _SOLVER_H_

extern int sudoku_helper(int puzzle[][9], int row, int column);
extern int is_valid(int number, int puzzle[][9], int row, int column);

#endif /*_SOLVER_H_*/