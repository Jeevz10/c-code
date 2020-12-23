// CS1010 AY2013/4 Semester 1
// PE2 Ex1: compatible.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Given two names, strike off matching letters in the names,
// find the number of remaining letters in the names, and 
// determines if the names are compatible.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Name has at most 35 characters
#define MAXLEN 36

// Fill in your function prototypes below

void readName(char []);
void match(char [],char [],int *,int *);

int main(void) {
	char name1[MAXLEN], name2[MAXLEN];
	int remain1,   // number of remaining characters in name1 
	    remain2;   // and name2 after matching

	printf("Enter 2 names below:\n"); // given, do not remove/change this line
	readName(name1);                  // given, do not remove/change this line
	readName(name2);                  // given, do not remove/change this line

	// Call the match() function here
	
	match(name1,name2,&remain1,&remain2);
	
	printf("Number of letters remaining in 1st name = %d\n", remain1);
	printf("Number of letters remaining in 2nd name = %d\n", remain2);
	
	if (((remain1 % 2 == 0) && (remain2 % 2 == 0)) || ((remain1 % 2 == 1) && (remain2 % 2 == 1))) {
		printf("The names are compatible.\n");
	}
	else {
		printf("The names are not compatible.\n");
	}

	return 0;
}

void readName(char name[]) {
	int len;

	fgets(name,MAXLEN + 1,stdin);
//	getchar();

	len = strlen(name);

	if (name[len - 1] == '\n') {
		name[len - 1] = '\0';
	}
}

void match(char name1[],char name2[],int *remain1,int *remain2) {
	int len1,len2,i = 0,j = 0,sum1 = 0,sum2 = 0,length1,length2;
	char ch;

	len1 = strlen(name1);
	len2 = strlen(name2);
	
	length1 = len1;
	length2 = len2;

	for (i = 0;i < len2;i++) {
		if (isspace(name2[i])) {
			sum2++;
		}
	}

	for (i = 0;i < len1;i++) {
		ch = name1[i];

		if (ch == ' ') {
			sum1++;
			continue;
		}
		for (j = 0;j < len2;j++) {
			if (tolower(name2[j]) == tolower(ch)) {
				length1--;
				length2--;
				name1[i] = ' ';
				name2[j] = ' ';
				break;
			}
		}
	}
	*remain1 = length1 - sum1;
	*remain2 = length2 - sum2;
}

// To students: You must write the function's description here. [1 mark]
// readName() function


// To students: You must write the function's description here. [1 mark]
// match() function


