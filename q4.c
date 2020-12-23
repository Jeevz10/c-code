// q4.c
#include <stdio.h> 

int main(void) {
	char board[2][4] = { {'a','b','c','\0'}, {'d','e','f','\0'} };
	int i;

	for (i=0; i<2; i++)
		printf("%s\n", board[i]);

	return 0;
}

