// CS1010 AY2014/5 Semester 1
// PE1 Ex2: happy.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 
#include <stdio.h>
#include <math.h>

int computeHappyNumbers(int lower, int upper);
int main(void){
	int lower1, upper1, lower2, upper2, number1, number2;

	printf("Enter first range: ");
	scanf("%d %d",&lower1,&upper1);

	printf("Enter second range: ");
	scanf("%d %d",&lower2,&upper2);
	
	number1 = computeHappyNumbers(lower1,upper1);
	number2 = computeHappyNumbers(lower2,upper2);

	printf("The numbers of happy numbers in the two ranges are: %d %d\n", number1, number2);

	if (number1 > number2) {
	printf("There are more happy numbers in the first range.\n");
	}
	else if (number1 < number2)  {
	printf("There are more happy numbers in the second range.\n");
	}
	else {
	printf("The numbers of happy numbers in both ranges are the same.\n");
	}
	return 0;
}

int computeHappyNumbers(int lower,int upper) {
	int tempvariable = 0,digit,counter = lower,happy = 0;

	for (counter = lower;counter <= upper;counter++) {
		do {
			while (counter != 0) {
				digit = counter % 10;
				tempvariable += digit * digit;
				counter /= 10;
			}
			counter = tempvariable;
			if (counter == 1) {
				happy += 1;
				break;
			}
		}
			while ((counter != 0) && (counter != 1) && (counter != 4) && (counter != 16) && (counter != 20) && (counter != 37) && (counter != 42) && (counter != 58) && (counter != 89) && (counter != 145));
}

	return happy;
}

