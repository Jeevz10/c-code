#include <stdio.h>
#include <math.h>

int isAscending(int,int,int);

int main(void) {
	
	int num_1, num_2, num_3, returns;
	
	printf("Enter 3 positive integers: ");
	scanf("%d %d %d", &num_1, &num_2, &num_3);
	
	returns = isAscending( num_1, num_2, num_3);
	
	if ( returns == 1) {
		
		printf("The integers are %d, %d and %d\n", num_1, num_2, num_3);
		printf("Yes\n");
	}
	
	else {
		printf("The integers are %d, %d and %d\n", num_1, num_2, num_3);
		printf("No\n");
	}
	
	return 0;
}

int isAscending( int num_1, int num_2, int num_3) {
	
	int digit_1, digit_2, digit_3, returns;
	
	digit_1 = (( (num_1) / 100) % 10);
	digit_2 = (( (num_2) / 100) % 10);
	digit_3 = (( (num_3) / 100) % 10);
	
	if ((digit_3 > digit_2) && (digit_2 > digit_1)) {
		
		returns = 1;
	}/*
	else if ((digit_2 > digit_1) && (digit_2 > digit_3)) {
		
		returns = 1;
	}
	
	else if ((digit_3 > digit_1) && (digit_3 > digit_2)) {
		
		returns = 1;
	}
	*/
	else {
		
		returns = 0;
	}
	
	return returns;
}
