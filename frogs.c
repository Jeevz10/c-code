/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex3
 * frogs.c
 * This program simulates a way for the 2 clans of frogs to cross a river
 * Jeevan Neralakere Somashekhar 
 * C04
 */
#include <stdio.h>

int jump(int, int[]); // This function takes in the user input,adjust the position of the frogs accordingly and counts the number of jumps made
void printBridge(int, int[]); // This function prints the position of each type of frog on either side of the bridge 
int checkGameState(int, int[]); // This function tests whether all the frogs have crossed the bridge or whether they are stuck or whether they are still more jumps that can be made

int main(void) {

	int bridge[1000];
	int i;
	int lengthOfBridge;

	printf("Please enter the length of the bridge: ");
	scanf("%d", &lengthOfBridge);

 	for (i=0; i<lengthOfBridge; i++) {
		int frogType;

		printf("Please insert frogs at position %d: ", i);
		scanf("%d", &frogType);

		bridge[i] = frogType;
	}

	printf("Input completed\n");
	printBridge(lengthOfBridge, bridge);

	printf("Please start moving the frogs\n");

	jump(lengthOfBridge,bridge);

	return 0;
}

//This function is provided for you
/**
 * Prints out the current state on the bridge
 * @param size (int) represents the size of bridge
 * @param bridge[] contains the current state of the bridge
 **/
void printBridge(int size, int bridge[]) {

	int i;
	printf("Position: ");
	for (i=0; i<size; i++) {
		printf("%2d ", i);
	}
	printf("\n");

	printf("Bridge:   ");
	for (i=0; i<size; i++) {
		printf("%2d ", bridge[i]);
	}
	printf("\n");
}
/**
 * PreCond: Size > 0
 * This function takes in the user input and checks if the frog at that position can make a jump
 * If cannot make a jump, the function will ask user input again.
 * After each successful jump, the array bridge[] will be passed on to the checkGameState where it checks 
 * if more jumps can be made, or no more jumps can be made, or whether all the frogs have crossed the bridge
 */
int jump(int size,int bridge[]) {
	int canJump,position,jumps = 0;

	do {
		printf("Move the frog at position: ");
		scanf("%d",&position);

		if (bridge[position] == -1) {
			if (bridge[position - 1] == 0) {
				bridge[position] = 0;
				bridge[position - 1] = -1;
				jumps++;
				printBridge(size,bridge);
			}
			else if (((bridge[position - 1] == 1) || (bridge[position - 1] == -1)) && (bridge[position - 2] == 0)) {
				bridge[position -2] = -1;
				bridge[position] = 0;
				jumps++;
				printBridge(size,bridge);
			}
			else {
				printf("Invalid move!\n");
			}
		}
		else if (bridge[position] == 1) {
			if (bridge[position + 1] == 0) {
				bridge[position] = 0;
				bridge[position + 1] = 1;
				jumps++;
				printBridge(size,bridge);
			}
			else if (((bridge[position + 1] == 1) || (bridge[position + 1] == -1)) && (bridge[position + 2] == 0)) {
				bridge[position + 2] = 1;
				bridge[position] = 0;
				jumps++;
				printBridge(size,bridge);
			}
			else {
				printf("Invalid move!\n");
			}
		}
		else {
			printf("Invalid move!\n");
		}
		canJump = checkGameState(size,bridge);
	} while (canJump == 1);

	if (canJump == 0) {
		printf("Oh no! It seems like the two clans of frogs are stuck!\n");
		
		return 0;
	}
	if (canJump == 2) {
		printf("Congratulations! The frogs took %d jumps to cross the bridge!\n",jumps);

		return 0;
	}
}
/**
 * PreCond: Size > 0
 * This function checks if more moves can be made, or no more moves can be made or if all the frogs have crossed the bridge 
 * by breaking it down into many scenarios.
 * If the 2 frogs on the right of thr bridge are 1, and the 2 frogs on the left of the bridge are -1, we will check from 0 to position of bridge for -1, and 
 * from the position after bridge to size - 1 for 1. If there are abnormalies, we will return a status "canJump" = 0
 * If all is good, we return canJump = 1. 
 * Another scenario is when the bridge is in position 1 or size - 2. If it is at position 1 and the frog on its left is -1, we check for all the frogs after it for 1. 
 * Similarly, for size - 2, if the frog on the right is 1, we will check for all on the left for frog -1. 
 * The following is the summary for the canJump status. 
 * 0 stands for no more moves can be made
 * 1 stands for more moves can be made
 * 2 stands for all frogs have crossed the bridge 
 */
int checkGameState(int size,int bridge[]) {
	int i = 0,canJump,pos_emptyspace;

	for (i = 0;i < size;i++) {
		if (bridge[i] == 0) {
			pos_emptyspace = i;
			break;
		}
	}
	if ((pos_emptyspace == 0) && (bridge[pos_emptyspace + 1] == 1) && (bridge[pos_emptyspace + 2] == 1)) {
			return canJump = 0;
	}
	if ((pos_emptyspace == size - 1) && (bridge[pos_emptyspace - 1] == -1) && (bridge[pos_emptyspace - 2] == -1)) {
			return canJump = 0;
	}
	if (pos_emptyspace == 1) {
		if (bridge[pos_emptyspace - 1] == 1) {
			return canJump = 1;
		}
		if (bridge[pos_emptyspace - 1] == -1) {
			if ((bridge[pos_emptyspace + 1] == -1) || (bridge[pos_emptyspace + 2] == -1)) {
				return canJump = 1;
			}
			else {
				for (i = pos_emptyspace + 1;i < size;i++) {
					if (bridge[i] != 1) {
						return canJump = 0;
					}
				}
				return canJump = 2;
			}
		}
	}
	if (pos_emptyspace == size - 2) {
		if (bridge[pos_emptyspace + 1] == -1) {
			return canJump = 1;
		}
		if (bridge[pos_emptyspace + 1] == 1) {
			if ((bridge[pos_emptyspace - 1] == 1) || (bridge[pos_emptyspace - 2] == 1)) {
				return canJump = 1;
			}
			else {
				for (i = pos_emptyspace - 1;i >= 0;i--) {
					if (bridge[i] != -1) {
						return canJump = 0;
					}
				}
				return canJump = 2;
			}
		}
	}

	if ((bridge[pos_emptyspace - 1] == -1) && (bridge[pos_emptyspace - 2] == -1) && (bridge[pos_emptyspace + 1] == 1) && (bridge[pos_emptyspace + 2] == 1)) {
		for (i = 0;i < pos_emptyspace;i++) {
			if (bridge[i] != -1) {
				return canJump = 0;
			}
		}
		for (i = pos_emptyspace + 1;i < size;i++) {
			if (bridge[i] != 1) {
				return canJump = 0;
			}
		}
		return canJump = 2;
	}
	else {
		return canJump = 1;
	}
}



