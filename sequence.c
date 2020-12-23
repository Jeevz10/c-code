/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex2
 * Given a 12x12 integer array, fill it with integers, and
 * find the longest sequence of a digit that appears in 
 * the array horizontally, vertically or diagonally.
 * Jeevan Neralakere Somashekhar 
 * C04
 */

#include <stdio.h>
#define DIM 12

// function prototypes below
int scanBoard(int arr[][DIM]);
int search(int arr[][DIM],int,int *,int *);
void printBoard(int arr[][DIM],int);
int main(void) {
	int board[DIM][DIM] = { {0} };
	int search_digit;     
	int length; // length of the longest sequence of search digit
	int bestRow,bestCol;// where the longest sequence of search digit starts in each board
	int *bestRow_ptr = &bestRow, *bestCol_ptr = &bestCol; 

	// call scanBoard() 
	search_digit = scanBoard(board);
	// call search()
	length = search(board,search_digit,&bestRow,&bestCol);

	if (length > 0) {
		printf("Length of longest sequence = %d\n", length); 
		printf("Start at (%d,%d)\n", *bestRow_ptr, *bestCol_ptr);
	}
	else
		printf("No such sequence.\n");

	return 0;
}

// scans the input to a 2d array
// and returns the search digit 
int scanBoard(int arr[][DIM]) {
	int row,column,i = 0,search_digit;

	for (row = 0;row < DIM;row++) {
		for (column = 0;column < DIM;column++) {
			scanf("%d",&arr[row][column]);
		}
	}
	scanf("%d",&search_digit);
	return search_digit;
}

// Pre cond: search digit is within the range
// searches for the longest length of the search digit in the board
int search(int arr[][DIM],int search_digit,int *bestRow_ptr,int *bestCol_ptr) {
	int row,column,i = 0,start_r,start_c,length = 0,arrA[6] = {0},max = arrA[0];
	
	for (row = 0;row < DIM;row++) {
		for (column = 0;column < DIM;column++) {
			// Checks for south 
			if ((row != DIM - 1) && (arr[row + 1][column] == search_digit)) {
				for (i = 0;i < DIM;i++) {
					if (arr[row + i][column] == search_digit) {
						arrA[1]++;
						if (row + i == DIM - 1) {
							break;
						}
					}
					else {
						break;
					}
				}
			}
			// Checks for east
			if ((column != DIM - 1) && (arr[row][column + 1] == search_digit)) {
				for (i = 0;i < DIM;i++) {
					if (arr[row][column + i] == search_digit) {
						arrA[3]++;
						if (column + i == DIM - 1) {
							break;
						}
					}
					else {
						break;
					}
				}
			}
			// Checks for south east
			if (((row != DIM - 1) || (column != DIM - 1)) && (arr[row + 1][column + 1] == search_digit)) {
				for (i = 0;i < DIM;i++) {
					if (arr[row + i][column + i] == search_digit) {
						arrA[5]++;
						if ((row + i == DIM - 1) || (column + i == DIM - 1)) {
							break;
						}
					}
					else {
						break;
					}
				}
			}
			max = arrA[0];
			for (i = 0;i < 6;i++) {
				if (arrA[i] > max) {
					max = arrA[i];
				}
			}
			if (max > length) {
				length = max;
				start_r = row;
				start_c = column;
			}
			for (i = 0;i < 6;i++) {
				arrA[i] = 0;
			}
		}
		}
	*bestRow_ptr = start_r;
	*bestCol_ptr = start_c;
	return length;
}

