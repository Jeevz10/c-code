#include <stdio.h>
#include <math.h>

int get_magic(int); 
int main(void) {
	int input_1, input_2, magicnum1, magicnum2;

	printf("Enter 1st value: ");
	scanf("%d", &input_1);

	magicnum1 = get_magic(input_1);

	printf("Magic number = %d\n", magicnum1);

	printf("Enter 2nd value: ");
	scanf("%d", &input_2);

	magicnum2 = get_magic(input_2);

	printf("Magic number = %d\n", magicnum2);

	return 0;
}

int get_magic(int input) {
	
	int digit_1, digit_3, digit_5, magic, imt;

	if ( input < 100) {

		digit_1 = ( input % 10); 
		magic = digit_1;

	}

	else if ( input < 1000) {

		digit_3 = ( input / 100);
		digit_1 = ( input % 10);
		magic = ((digit_1 + digit_3) % 10);

	}

	else if ( input < 10000) {

		imt = ( input / 100);
		digit_3 = ( imt % 10);
		digit_1 = ( input % 10);
		magic = (( digit_1 + digit_3) % 10);

	}

	else if ( input < 100000) { 

		digit_5 = ( input / 10000);
		imt = ( input / 100);
		digit_3 = ( imt % 10);
		digit_1 = ( input % 10);
		magic = ((digit_5 + digit_3 + digit_1) % 10);

	}

	return magic;

}


