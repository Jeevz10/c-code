/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex2
 * square_free.c
 * Jeevan Neralakere Somashekhar 
 * C04
 * This programme reads 4 positive integer in the following sequence: lower1,
 * upper1, lower2, upper2 and computes the number of square-free integers 
 * in the two ranges. Square-free integers are positive integers divisible by
 * no square number except 1.
 */

#include <stdio.h>
#include <math.h> 
int compute_sqrfree(int,int); /* Function prototype of the function "compute_sqrfree". This function calculates the number of square-free integers within the given range.*/

int main(void) {
	int lower1,upper1,lower2,upper2,num1,num2;

	printf("Enter four positive integers: ");
	scanf("%d %d %d %d",&lower1,&upper1,&lower2,&upper2);
	/* The variables "num1" and "num2" stores the value of the number of square-free integers within the given range*/
	num1 = compute_sqrfree(lower1,upper1);
	num2 = compute_sqrfree(lower2,upper2);
	
	/* The following if-else statements compares the values of the num1 and num2, and outputs the relevant answer.*/
	if (num1 > num2) {
		printf("Range [%d, %d] has more square-free numbers: %d\n",lower1,upper1,num1);
	}

	else if (num2 > num1) {
		printf("Range [%d, %d] has more square-free numbers: %d\n",lower2,upper2,num2);
	}
	
	else	{
		printf("Both ranges have the same number of square-free numbers: %d\n",num1);
	}

	return 0;
}

/* This function computes the number of square-free integers within the given range*/
int compute_sqrfree(lower,upper) {
	/* The variable "counter" is the test divisor. 
	 * The variable "limit" has the value of the lower number of the range input.
	 * The variable "square_sum" stores the total number of integers within the range that can be divided by a square number.
	 * The variable "actualsum" stores the total number of square free integers within the given range.*/
	int counter = 2,actualsum, limit = lower,tempvariable,square_sum = 0;
	/* For each number within the range, starting from the lowest number of the range, we test the divisibility of the number with an increasing number of square numbers.*/
	for (limit = lower;limit <= upper;limit++) {
		for (counter = 2; ((counter * counter) <= limit); counter++) {
			tempvariable = (limit % (counter * counter));
			/* If the particular number within the range can be divided by a square number, it will give a remainder of 0 and we add 1 count to the variable "sum".*/
			if (tempvariable == 0) {
				square_sum += 1;
				break;
			}
		}
	}
	/* To calculate actualsum, we minus off the number of numbers that can divided by a square integer from the total number of integers within the given range.*/
	actualsum = ((upper - lower + 1) - square_sum);
	return actualsum;
}


