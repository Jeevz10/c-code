// cond_op1.c
// Illustrating the conditional operator ? :
#include <stdio.h>

int main(void) {
	int n, p; 

	printf("Enter an integer: ");
	scanf("%d", &n);

	p = ((n > 5) && (n < 20)) ? 33 : -77;
	printf("p = %d\n", p);

	return 0;
}

