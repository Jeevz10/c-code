/**
 * rabbit.c 
 * A rabbit can jump at most 50 centimetres. It needs to cross a
 * river, with rocks positioned in a straight line in the river.
 * The program computes the minimum number of jumps for the rabbit
 * to cross to the other side of the river.
 */

#include <stdio.h>
void scanArray(int [],int);
int countJumps(int [],int);

int main(void) {
	int num_rocks,counter = 0,jumps,position[20];            // including opposite bank

	printf("Enter number of rocks: ");
	scanf("%d", &num_rocks);

	scanArray(position,num_rocks);

	for (counter = 0;counter < (num_rocks - 1);counter++) {
		if ((position[0] - 0) > 50) {
			printf("-1\n");
			break;
		}
		if (((position[counter + 1]) - (position[counter]) > 50)) {
			printf("-1\n");
			break;
		}
		if (counter == (num_rocks - 2)) {
			jumps = countJumps(position,num_rocks);
			printf("%d\n",jumps);
			break;
	}
	}
	return 0;
}
void scanArray(int arr[],int size) {
	int counter;

	for (counter = 0;counter<size;counter++) {
		scanf("%d",&arr[counter]);
	}
}
// Counts the minimum number of jumps the rabbit needs
// to take to get to the other side of the river.
// Precond: size > 0
int countJumps(int position[], int size) {
	int jumps = 0,counter2 = 0,limit = 50;

	while (limit < position[size - 1]) {
		for (counter2 = 0;counter2 < size;counter2++) {
			if (position[counter2] > limit) {
				limit = position[counter2 -1] + 50;
				jumps++;
				break;
			}
		}
	}
	jumps += 1;
	return jumps;
}

