// partition.c
#include <stdio.h>
void scanArray(int [],int);
void printArray(int [], int);
void partition(int [],int,int);

int main(void) {
	int size,pivot,list[20];

	printf("Enter the number of elements: ");
	scanf("%d", &size);

	printf("Enter %d integers: ", size);
	scanArray(list,size);

	printf("Enter pivot: ");
	scanf("%d",&pivot);
	
	partition(list,size,pivot);

	printArray(list,size);

	return 0;
}

void scanArray(int arr[],int size) {
	int counter = 0;
	for (counter = 0;counter < size;counter++) {
		scanf("%d",&arr[counter]);
	}
}
// Print array arr
void printArray(int arr[], int size) {
	int i;

	for (i=0; i<size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void partition(int arr[],int size,int pivot) {
	int tempvariable,tempvariable2,counter = 0,counter2 = counter;

	for (counter = 0;counter < size;counter++) {
		if (arr[counter] >= pivot) {
			tempvariable = arr[counter];
		}
		for (counter2 = counter;counter2 < size;counter2++) {
			if (arr[counter2] < pivot) {
				tempvariable2 = arr[counter2];
				arr[counter] = tempvariable2;
				arr[counter2] = tempvariable;
				break;
			}
		}
	}
}
