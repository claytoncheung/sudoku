#ifndef _VALIDATOR_H_
#define _VALIDATOR_H_
#define NUM_OF_THREADS 27

extern void *checkRow(void *rowNum);
extern void *checkColumn(void *colNum);
extern void *checkBox(void *boxNum);
extern int validateAll(int puzzle[9][9]);
extern void ins_sort(int *array);

#endif /*_VALIDATOR_H_*/
