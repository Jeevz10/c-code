// CS1010 AY2014/5 Semester 1
// PE2 Ex2: 2048.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 4
#define LENGTH 21

void play(int [][SIZE],char []);
int exists(int [][SIZE],int);
void readGrid(int [][SIZE]); 
void printGrid(int [][SIZE]); 

int main(void) {
	int grid[SIZE][SIZE],target,isgood;
	char directions[LENGTH];

	printf("Enter grid:\n");
	readGrid(grid);
//	getchar();
	
	printf("Enter directions: ");
	scanf("%s",directions);

	printf("Enter target: ");
	scanf("%d",&target);
//	printf("4\n");
//	printf("%s\n",directions);
//	printf("%d\n",target);
	play(grid,directions);

	isgood = exists(grid,target);
	
	if (isgood == 1) {
		printGrid(grid);
		printf("%d is formed.\n", target);
	}
	else {
		printGrid(grid);
		printf("%d is not formed.\n", target);
	}

	return 0;
}

// Read in the grid
void readGrid(int grid[][SIZE]) {
	int i,j;

	for (i=0; i<SIZE; i++)
		for (j=0; j<SIZE; j++)
			scanf("%d",&grid[i][j]);
}

// Print out the grid
void printGrid(int grid[][SIZE]) {
	int i,j;

	for (i=0; i<SIZE; i++) {
		for (j=0; j<SIZE; j++)
			printf("%d ",grid[i][j]);
		printf("\n");
	}
}

void play(int grid[][SIZE],char directions[]) {
	int i,r,c,move,len,row,column;
	char dir;
	
	len = strlen(directions);

	for (i = 0;i < len;i++) {
		dir = directions[i];

		if (dir == 'U') {
			for (r = 1;r < SIZE;r++) {
				for (c = 0;c < SIZE;c++) {
					
					if (grid[r][c] == 0) {
						continue;
					}
					for (row = r;row > 0;row--) {
						if (grid[row][c] == 0) {
							break;
						}
						if (grid[row-1][c] == 0) {
							grid[row-1][c] = grid[row][c];
							grid[row][c] = 0;
						}
						else if (grid[row-1][c] == grid[row][c]) {
							grid[row-1][c] = 2 * grid[row][c];
							grid[row][c] = 0;
							break;
						}
						else if (grid[row-1][c] != grid[row][c]) {
							break;
						}
					}
				}
			}
		}

		else if (dir == 'L') {
			for (r = 0;r < SIZE;r++) {
				for (c = 1;c < SIZE;c++) {
	
					if (grid[r][c] == 0) {
						continue;
					}
					for (column = c;column > 0;column--) {
						if (grid[r][column] == 0) {
							break;
						}
						if (grid[r][column-1] == 0) {
							grid[r][column - 1] = grid[r][column];
							grid[r][column] = 0;
						}
						else if (grid[r][column - 1] == grid[r][column]) {
							grid[r][column - 1] = 2 * grid[r][column];
							grid[r][column] = 0;
							break;
						}
						else if (grid[r][column-1] != grid[r][column]) {
							break;
						}
					}
				}
			}
		}
	}
}

int exists(int grid[][SIZE],int target) {
	int r,c;

	for (r = 0;r < SIZE;r++) {
		for (c = 0;c < SIZE;c++) {
			if (grid[r][c] == target) {
				return 1;
			}
		}
	}
	return 0;
}



