/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex1
 * prerequisites.c
 * This programme checks to see if the module exists, and if it does, it checks for its prerequisites
 * Jeevan Neralakere Somashekhar
 * C04
 */

// Add the preprocessor include statements below
#include <string.h>
#include <ctype.h>
#include <stdio.h> 

#define MAX_MOD  10
#define MAX_LEN  7

void scanModules(char [][MAX_LEN],int); // Function prototype that reads in the input into array 
int computePrereq(char [][MAX_LEN], int, char [], char [][MAX_LEN]); // Function prototype that Determines if module exists, and if it does, checks for its prerequisites
void printPrereq(char [][MAX_LEN], int, char []); // Function prototype that prints corresponding statments

// Note: the main() function is given below. You are NOT to modify it.
int main(void) {
	int numModules, numPrereq;
	char codes[MAX_MOD][MAX_LEN],         // the list of modules codes
			 target[MAX_LEN],                 // the target module
			 prerequ[MAX_MOD][MAX_LEN] = {{'\0'}}; // prerequisites of the target module
	
	printf("Enter number of modules: ");
	scanf("%d",&numModules);
	getchar();
	
	printf("Enter %d modules:\n",numModules);
	scanModules(codes,numModules);

	printf("Choose a module: ");
	scanf("%s", target);

	numPrereq = computePrereq(codes, numModules, target, prerequ);

	printPrereq(prerequ, numPrereq, target);

	return 0;
}
// Pre cond: Size of each module has to be at most 6 alphanumeric characters long
void scanModules(char code[][MAX_LEN],int numModules) {
	int i = 0;

	for (i = 0;i < numModules;i++) {
		scanf("%s",code[i]);
	}
}

// Print the prerequisites
// This function is given. You are NOT to modify it.
void printPrereq(char prerequisites[][MAX_LEN], int numPrereq, char target[]) {
	int i;

	if (numPrereq == -1) {
		printf("No such module %s\n", target);
	}
	else if (numPrereq == 0) {
		printf("No prerequisites for %s\n", target);
	}
	else {
		printf("Prerequisites for %s:",target);
		for (i = 0; i < numPrereq; i++){
			printf(" %s", prerequisites[i]);
		}
		printf("\n");
	}
}
// This function determines if target module exists withing the list of modules, and if it does, checks for its prerequisites
int computePrereq(char code[][MAX_LEN],int numMods,char target[],char prerequ[][MAX_LEN]) {
	int i = 0,j = 0,size = 0,k = 0;
	// Check if module exists, if it doesnt, return -1
	for (i = 0;i <numMods; i++) {
		if (strcmp(code[i],target) == 0) {
			break;
		}
		if (i == numMods - 1) {
			return -1;
		}
	}
	// Checks for modules that has the same 2 letters as target module, first digit smaller than target module, and remaining digits not greater than target module
	for (i = 0;i < numMods;i++) {
		if ((code[i][0] == target[0]) && (code[i][1] == target[1])) {
			if((code[i][2] < target[2])) {
				if ((code[i][3] <= target[3]) && (code[i][4] <= target[4]) && (code[i][5] <= target[5])) {
					size++;
					strcpy(prerequ[k],code[i]); // Such a module will get copied into a seperate array 
					k++;
				}
			}
		}
	}

	if (size == 0) {
		return 0;
	}
	else {
		return size;
	}
}




