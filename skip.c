#include <stdio.h>
#include <math.h>

int skipCount(int,int,int);
int countOddDigits(int);

int main(void) {

	int startPos,lower,upper,endPos;

	printf("Enter starting position: ");
	scanf("%d", &startPos);

	printf("Enter lower bound and upper bound: ");
	scanf("%d %d", &lower, &upper);
	
	endPos = skipCount(startPos,lower,upper);

	printf("The ending position is %d.\n",endPos);

	return 0;
}

// int countOddDigits(int);
int skipCount(int startPos,int lower,int upper) {
	int counter = lower,totalSkips,sumtotalOdd = 0,tempvariable,endPos; 
	
	for (counter = lower; counter <= upper; counter++) {
		tempvariable = countOddDigits(counter);
		sumtotalOdd += tempvariable; 
	}
	totalSkips = (upper - lower + 1) + sumtotalOdd;
	endPos = totalSkips + startPos;
	if (endPos <= 5) {

		endPos = endPos;
	}

	else {
		while (endPos > 5) {
			endPos -= 5;
		}
	}
	return endPos;
}

int countOddDigits(int counter) {
	int digit,totalOddno = 0;

	while (counter != 0) {
		digit = counter % 10;
		if (digit % 2 == 1) {
			totalOddno += 1;
		}
		counter = counter / 10;
	}
	return totalOddno;
}
	


		
