#include <stdio.h>
#define MAX_SLICES 200000

int totalCherries(int [],int);
void scanArray(int [],int);
int maxCherries(int [], int);

int main(void){
	int slices,cherries[MAX_SLICES],max;

	printf("Enter number of slices: ");
	scanf("%d",&slices);

	printf("Enter numbers of cherries: ");
	scanArray(cherries,slices);

	max = maxCherries(cherries,slices);

	printf("The maximum number of cherries Alice can get is %d.\n",max); // Incomplete

	return 0;
}

void scanArray(int arr[],int size) {
	int counter = 0;

	for (counter = 0;counter < size;counter++) {
		scanf("%d",&arr[counter]);
	}
}

int maxCherries(int arr[],int size) {
	int total,tempvariable,max = 0,sum = 0,counter = 0,counter2 = counter;

	total = totalCherries(arr,size);

	for (counter = 0;counter < size;counter++) {
		for (counter2 = counter;counter2 < (size + counter);counter2++) {
			sum += arr[counter2 % size];
			if (sum > (total / 2)) {
				break;
			}
			if (sum > max) {
				tempvariable = sum;
				max = tempvariable;
			}
		}
		sum = 0;
	}
	return max;
}

int totalCherries(int arr[], int size) {
	int counter = 0,total = 0;

	for (counter = 0;counter < size; counter++) {
		total += arr[counter];
	}
	return total;
}
