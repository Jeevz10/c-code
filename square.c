/**
 * CS1010 AY2017/8 Semester 1 Lab5 Ex1
 * square.c
 * Given the size of a square and the values in
 * in the square, this program determines whether 
 * the given square is a semi-magic square.
 * Jeevan Neralakere Somashekhar
 * C04
 */

#include <stdio.h>
#define MAXSIZE 9

/* Function prototypes */
int scanSquare(int [][MAXSIZE]); 
void printArray(int [][MAXSIZE],int);
int isSemiMagic(int [][MAXSIZE],int);
int isSumSame(int [][MAXSIZE],int);
int isNumRepeated(int [][MAXSIZE],int);

int main(void) {
	int square[MAXSIZE][MAXSIZE],size;
	
	size = scanSquare(square);
	// if it is Semi-magic, it prints as follows or else it'll print the else statement 
	if ((isSemiMagic(square,size))) {
		printf("It is a semi-magic square.\n");
	}
	else {
		printf("It is not a semi-magic square.\n");
	}
	return 0;
}

// Read in size of square and values in the square. 
// Return the size of square.
int scanSquare(int square[][MAXSIZE]) {
	int r, c, size;

	printf("Enter size of square: ");
	scanf("%d", &size);

	printf("Enter values in the square: \n");
	for (r=0; r<size; r++) {
		for (c=0; c<size; c++) {
			scanf("%d", &square[r][c]);
		}
	}

	return size;
}
// Pre Cond: size > 0
// This function passes over to other two functions
int isSemiMagic(int square[][MAXSIZE],int size) {
	// if sum is same and if number is not repeated it returns 1, else 0
	if ((isSumSame(square,size)) && (isNumRepeated(square,size)) ){
		return 1;
	}
	else {
		return 0;
	}
}
// Pre Cond: size > 0
// Checks if each row and column has the same sum 
int isSumSame(int arr[][MAXSIZE],int size) {
	int row = 0,column = 0,currentSum = 0,actualSum;
	// Finds the sum of each column and checks if sum is same
	for (row = 0;row < size;row++) {
		for (column = 0;column < size;column++) {
			currentSum += arr[row][column];
		}
		if (row == 0) {
			actualSum = currentSum;
		}
		else if (currentSum != actualSum) {
			return 0;
		}
		currentSum = 0;
	}
	// Find the sum of each row and checks if sum is same
	for (column = 0;column < size;column++) {
		for (row = 0;row < size;row++) {
			currentSum += arr[row][column];
		}
		if (actualSum != currentSum) {
			return 0;
		}
		currentSum = 0;
	}
	return 1;
}
// Pre Cond: size > 0
// Checks if any of the numbers are repeated
 int isNumRepeated(int arr[][MAXSIZE],int size) {
	int counter = 1,column = 0,row = 0,numofNumbers = 0;
	
	for (counter = 1;counter <= (size * size);counter++) {
		for (row = 0;row < size;row++) {
			for (column = 0;column < size;column++) {
				if (counter == arr[row][column]) {
					numofNumbers++;
					break;
				}
			}
			if (counter == arr[row][column]) {
				break;
			}
			if (row == size - 1) {
				return 0;
			}
		}
	}
	return 1;
 }



