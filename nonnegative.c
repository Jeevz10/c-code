#include <stdio.h>
#include <math.h>

int nonNegative(int arr[],int size) {

	for (i = 0;i < size; i++) {

		if (arr[i] > 0) {
			num = 1;
			continue;
		}
		else {
			num = 0;
			break;
		}
		return num;
	}
}

int isSorted(int arr[],size) {

	int num1, num2, check;

	for (i = 0; i < size; i++) {

		num1 = arr[i];
		num2 = arr[i + 1];

		if (num2 > num1) {
			check = 1;
			continue;
		}

		else {
			check = 2;
			break;
		}
	}
	return check;
}



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int i, arr[];
	
	srand(time(NULL));

	arr[] = rand()%1000 + 1;
// How to account for size since there can be any number of integers?
	for (i = 0; i < ; ) {

		tempvariable = arr[i];

		if ((tempvariable == arr[]) && ((


