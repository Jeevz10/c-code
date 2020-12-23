/**
* CS1010 AY2017/8 Semester 1 Lab1 Ex3
* packing.c
* This program computes the maximum possible number of slabs that could be packed onto the tray.
* Jeevan Neralakere Somashekhar 
* C04
*/

#include <stdio.h>
#include <math.h>

int compute_max_slabs(int, int, int, int); // Function prototype of the function compute_max_slabs 
int main(void) {
	int tray_L, tray_W, slab_L, slab_W, max; // L stands for length and W stands for width. The variable max stands for the maximum number of slabs that could be fit into the tray.

	printf("Enter dimension of tray: ");
	scanf("%d %d", &tray_L,&tray_W);

	printf("Enter dimension of slab: ");
	scanf("%d %d", &slab_L, &slab_W);

	max = compute_max_slabs(tray_L, tray_W, slab_L, slab_W); // By using the function, a value will be returned into the variable max. 

	printf("Maximum number of slabs = %d\n", max);

	return 0;
}

// Function defintion of the function compute_max_slabs 
int compute_max_slabs(int tray_L, int tray_W, int slab_L, int slab_W) {
	int max_A, max_B, max; // Define new variables. max_A is the number of slabs that could be fit into using orientation A. max_B is the number of slabs that could be fit into using orientation B. Max is the biggest value out of max_A and max_B.

	max_A = ((tray_L / slab_L) * (tray_W / slab_W)); // Calculate the number of slabs using orientation A.
	max_B = ((tray_W / slab_L) * (tray_L / slab_W)); // Calculate the number of slabs using orientation B.

// Decipher whether max_A or max_B is bigger by using if else ; the bigger value out of max_A and max_B will be placed inside the variable max, and returned to the main function.
	if ( max_A > max_B ) {

		max = max_A; 
	}

	else {

		max = max_B; 
	}

	return max;
}

