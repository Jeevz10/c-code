// CS1010 AY2012/3 Semester 1 PE2 Ex1
//
// password.c
// This program checks whether a new password satisfies
// corresponding rules or not.
//
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define LEN 15

// function prototypes
int isValidPassword(char [], char [], char [], char []);

// main function complete, not to be changed!
int main(void) {
	char domain[LEN+1], userID[LEN+1], 
		 oldPasswd[LEN+1], newPasswd[LEN+1], confirmPasswd[LEN+1];

	printf("Domain: ");
	scanf("%s", domain);

	printf("UserID: ");
	scanf("%s", userID);

	printf("Old password: ");
	scanf("%s", oldPasswd);

	printf("New password: ");
	scanf("%s", newPasswd);

	printf("Confirm new password: ");
	scanf("%s", confirmPasswd);

	if ( isValidPassword(userID, oldPasswd, newPasswd, confirmPasswd) )
		printf("Password changed successfully!\n");
	else
		printf("Error: Invalid userID or password!\n");

	return 0;
}

// Check whether a new password is valid
int isValidPassword(char userID[], char oldPasswd[],
		char newPasswd[], char confirmPasswd[]) {
	int i = 0,j = 0,len,firstpos;
	
	len = strlen(newPasswd);

	if (len < 8) {
		return 0;
	}

	for (i = 0;i < len;i++) {
		if (isalpha(newPasswd[i]) || isdigit(newPasswd[i]) || newPasswd[i] == '_') {
		}
		else {
			return 0;
		}
	}
	
	for (i = 0;i < len;i++) {
		if (isalpha(newPasswd[i])) {
			firstpos = i;
			break;
		}
	}

	if (islower(newPasswd[firstpos])) {
		while (firstpos < len) {
			firstpos++;
			if (isupper(newPasswd[firstpos])) {
				break;
			}
			else if (firstpos == len - 1) {
				return 0;
			}
		}
	}
	else if (isupper(newPasswd[firstpos])) {
		while (firstpos < len) {
			firstpos++;
			if (islower(newPasswd[firstpos])) {
				break;
			}
			else if (firstpos == len - 1) {
				return 0;
			}
		}
	}
	
	for (i = 0;i < len;i++) {
		if (newPasswd[i] == userID[0]) {
			for (j = 1;j < strlen(userID);j++) {
				if (newPasswd[i + j] != userID[j]) {
					break;
				}
				if (j == strlen(userID) - 1) {
					return 0;
				}
			}	
		}
	}
	if (strcmp(newPasswd,oldPasswd) == 0) {
		return 0;
	}
	if (strcmp(newPasswd,confirmPasswd) != 0) {
		return 0;
	}

	return 1;
}

// You may write additional functions below if needed.
// However every function must be preceeded with a function description.

