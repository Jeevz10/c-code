/**
 * CS1010 AY2017/8 Semester 1 Lab4 Ex2
 * subsequence.c
 * This program reads in a list of integers and find the
 * k-interval subsequence with the largest sum.
 * Jeevan Neralakere Somashekhar
 * C04
 */

#include <stdio.h>
#include <limits.h>

int scan_list(int []); // This function scans the elements and inserts in into an array
void sum_subsequence(int [], int, int []); // This function determines which interval and starting position does the largest sum take place.  

int main(void) {
	int list[10], size; // array and actual number of elements entered
	int answers[3];     // stores the required answers

	size = scan_list(list); 

	sum_subsequence(list, size, answers);

	printf("Max sum %d of %d-interval subsequence starting at position %d.\n",
			answers[0], answers[1], answers[2]);

	return 0;
}

// Read in elements for the array arr and returns the 
// number of elements read.
// Postcond: i > 0
int scan_list(int arr[]) {
	int num, i;

	printf("Enter number of elements: ");
	scanf("%d", &num);
	printf("Enter %d element%s: ", num, (num>1)?"s":"");
	for (i=0; i<num; i++) {
		scanf("%d", &arr[i]);
	}

	return num;
}

// Precond: size > 0
// For a k-interval subsequence, we start by first evaluating each type of interval from the lowest possible interval, 1. 
// For each interval there on after, we start to sum up the different positions of the subsequence, starting from the first position, position 0.
// After we are done evaluating position 0, we compare the sum to the max sum attain so far. The initial max is the smallest integer value possible. 
// After we compare the subsequence which started from position 0, we move on to start from positon 1, and carry on the same action for the rest of the subsequences in the intervals.
//   ans[0] = maximum sum of solution subsequence
//   ans[1] = interval k of the solution subsequence
//   ans[2] = start position of the solution subsequence
void sum_subsequence(int arr[], int size, int ans[]) {
	int i = 1,j = 0,k = j,sum[10] = {0},max = INT_MIN,interval,position;

	for (i = 1;i <= size;i++) {
		for (j = 0;j <= i - 1;j++) {
			for (k = j;k < size;k += i) {
				sum[i - 1] += arr[k];
			}
			if (sum[i - 1] > max) {
				interval = i;
				position = j;
				max = sum[i - 1];
			}
			sum[i - 1] = 0;
		}
	}

	ans[0] = max;
	ans[1] = interval;
	ans[2] = position;
}
