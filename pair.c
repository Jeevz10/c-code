// pair.c
#include <stdio.h>

int findPair(int [], int, int, int *, int *);

int main() {
	int size,arr[10],i = 0,tgtsum,num1,num2,*num1_ptr = &num1,*num2_ptr = &num2;

	printf("Please enter the number of elements: ");
	scanf("%d",&size);

	//input the elements into array
	printf("Please enter %d integers: ", size);
	for (i = 0;i < size;i++) {
		scanf("%d",&arr[i]);
	}

	printf("Please enter the target sum: ");
	scanf("%d",&tgtsum);

	if (findPair(arr,size,tgtsum,&num1,&num2)) {
		printf("The pair of values are %d and %d.\n",*num1_ptr,*num2_ptr);
	}
	else {
		printf("No solution!\n");
	}

	return 0;
}

int findPair(int arr[10],int size,int tgtsum,int *num1_ptr,int *num2_ptr) {
	int i = 0,j = 0,sum = 0;

	for (i = 0;i < size;i++) {
		for (j = i;j < size;j++) {
			sum = arr[i] + arr [j];

			if (sum == tgtsum) {
				*num1_ptr = arr[i];
				*num2_ptr = arr[j];
				return 1;
			}
		}
	}
	return 0;
}
