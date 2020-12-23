// sumDigits.c
#include <stdio.h>
#include <ctype.h> 

int main(void) {
	int ch,sum = 0;

	printf("Enter input: ");
	
	while (!isspace(ch)) {
		ch = getchar();
		if (isdigit(ch)) {
		sum += ch - '0';
		}
	}

	printf("Sum = %d\n", sum);

	return 0;
}

