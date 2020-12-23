// cond_op2.c
#include <stdio.h>

int main(void) {
	int a, b, max;

	printf("Enter 2 integers: ");
	scanf("%d %d", &a, &b);

	max = ( a > b) ? a : b;

	printf("max = %d\n", max);

	return 0;
}

