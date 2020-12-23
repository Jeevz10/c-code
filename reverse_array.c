// reverse_array.c
// Reverse all values in an integer array.
#include <stdio.h>
#define MAX_SIZE 15

int readArray(int []);
void printArray(int [], int);
void reverseArray(int [], int);
void reverseArray_recur(int [],int,int);

int main(void) {
	int list[MAX_SIZE], size;

	size = readArray(list);
	reverseArray(list, size);
	
	printArray(list, size);
	
	return 0;
}

// Read values into array.
// Return number of elements read.
int readArray(int arr[]) {
	int size, i;

	printf("Enter number of integers: ");
	scanf("%d", &size);
	printf("Enter integers: ");
	for (i=0; i<size; i++)
		scanf("%d", &arr[i]);

	return size;
}

// Print values in array
void printArray(int arr[], int size) {
	int i;

	printf("Reversed array: ");
	for (i=0; i<size; i++)
		printf("%d ", arr[i]);
//	printf("\n");
}

// Reverse all the values in the array arr
// Pre-cond: size >= 1
void reverseArray(int arr[], int size) {
	reverseArray_recur(arr,size,0);
}

void reverseArray_recur(int arr[],int size,int index) {
	int temp;

	if (index < size/2) {
		temp = arr[index];
		arr[index] = arr[size - index - 1];
		arr[size - index - 1] = temp;
		reverseArray_recur(arr,size,index + 1);
	}
}

