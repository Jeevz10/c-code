#include <stdio.h>
#include <math.h>

int getnumber(int);
char generatecode(int);

int main(void) {
	int number, nric;
	char checkcode;

	printf("Enter 7-digit NRIC number: ");
	scanf("%d", &nric);

	number = getnumber(nric);
	checkcode = generatecode(number);

	printf("Check code is %c\n", checkcode);

	return 0;

}

int getnumber( int nric) {

	int digit_7, digit_6, imt6, digit_5, imt5, digit_4, imt4, digit_3, imt3, digit_2, imt2, digit_1, sum;

	digit_7 = ( nric / 1000000);

	imt6 = ( nric / 100000);
	digit_6 = ( imt6 % 10);

	imt5 = ( nric / 10000);
	digit_5 = ( imt5 % 10);

	imt4 = ( nric / 1000);
	digit_4 = ( imt4 % 10);

	imt3 = ( nric / 100);
	digit_3 = ( imt3 % 10);
	
	imt2 = ( nric / 10);
	digit_2 = ( imt2 % 10);

	digit_1 = ( nric % 10);

	sum = ( 11 - ( (( digit_7 * 2) + ( digit_6 * 7) + ( digit_5 * 6) + ( digit_4 * 5) + ( digit_3 * 4) + ( digit_2 * 3) + ( digit_1 * 2)) % 11));
	
	return sum;

}

char generatecode( int number) { 
	
	char checkcode;

	if ( number == 1) {

		checkcode = 'A';
	}

	if ( number == 2) {

		checkcode = 'B';

	}

	if ( number == 3) {

		checkcode = 'C';

	}

	if ( number == 4) {

		checkcode = 'D';
	}

	if ( number == 5) {

		checkcode = 'E';
	}

	if ( number == 6) {

		checkcode = 'F';
	}

	if ( number == 7) {

		checkcode = 'G';
	}

	if ( number == 8) {
		
		checkcode = 'H';
	}

	if ( number == 9) { 

		checkcode = 'I';

	}

	if ( number == 10) {

		checkcode = 'Z';

	}

	if ( number == 11) {

		checkcode = 'J';

	}

	return checkcode;

}


