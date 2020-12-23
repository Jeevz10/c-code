// CS1010 AY2015/6 Semester 2 PE2 Ex1
//
// minefield.c
//
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#define MAX_SIZE 10

int readField(int [][MAX_SIZE]);
void printField(int [][MAX_SIZE], int);
void detonate(int [][MAX_SIZE],int,int [][MAX_SIZE],int *,int *);

int main(void) {
	int field[MAX_SIZE][MAX_SIZE], aftermath[MAX_SIZE][MAX_SIZE] = {{0}};
	int size,max,safe;
	
	size = readField(field);
	
	detonate(field,size,aftermath,&max,&safe);

	printf("Aftermath: \n");
	printField(aftermath, size);
	
	printf("Maximum damage: %d\n",max); // Incomplete
	printf("Number of safe areas: %d\n",safe); // Incomplete

	return 0;
}

// Read in a minefield
// Do NOT modify this function!
int readField(int field[][MAX_SIZE]) {
	int i,j, size;
	
	printf("Enter size: \n");
	scanf("%d", &size);
	
	printf("Enter minefield: \n");
	for (i=0; i<size; i++)
		for (j=0; j<size; j++)
			scanf("%d", &field[i][j]);
		
	return size;
}

// Print a minefield
// Do NOT modify this function!
void printField(int field[][MAX_SIZE], int size) {
	int i,j;
	
	for (i=0; i<size; i++){
		for (j=0; j<size; j++)
			printf("%d ", field[i][j]);
		printf("\n");
	}
}

void detonate(int field[][MAX_SIZE],int size,int am[][MAX_SIZE],int *max_ptr,int *safe_ptr) {
	int pwr,i = 0,j = 0,r = 0,c = 0,max = 0,safe = 0;

	for (r = 0;r < size;r++) {
		for (c = 0;c < size;c++) {
			pwr = field[r][c];

			if ((pwr == 0) || (pwr == 1)) {
				am[r][c] = pwr;
				continue;
			}
			else {
				for (j = 1;j < pwr;j++) {
					if ((r == 0) || (r - j < 0)) {
						break;
					}
					else {
						am[r - j][c] += 1;
					}
				}
				
				for (j = 1;j < pwr;j++) {
					if ((c == size -1) || (c + j > size - 1)) {
						break;
					}
					else {
						am[r][c + j] += 1;
					}
				}

				for (j = 1;j < pwr;j++) {
					if ((r == size -1) || (r + j > size - 1)) {
						break;
					}
					else {
						am[r + j][c] += 1;
					}
				}

				for (j = 1;j < pwr;j++) {
					if ((c == 0) || (c - j < 0)) {
						break;
					}
					else {
						am[r][c-j] += 1;
					}
				}
			}
			
			am[r][c] += 1;
		}
	}

	for (r = 0;r < size;r++) {
		for (c = 0;c < size;c++) {

			pwr = am[r][c];

			if (pwr > max) {
				max = pwr;
			}

			if (pwr == 0) {
				safe++;
			}
		}
	}

	*max_ptr = max;
	*safe_ptr = safe;
}



