// function_with_errors.c
#include <stdio.h>

int main(void) {
	void func(5);
	void func(3-7);

	return 0;
}

void func(y) {
	if (y<0) {
		printf("Nothing\n");
	}
	else {
		printf("Something\n");
	}
}

