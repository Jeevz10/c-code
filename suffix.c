#include <stdio.h>
#include <math.h>
#define ST 1
#define ND 2
#define RD 3
#define TH 4 

void printsuffix(int);

int main(void) {

	int value; 

	printf("Enter value: ");
	scanf("%d", &value);

	printsuffix(value);

	return 0;

}

void printsuffix( int value) {
	
	int digit, twodigits;
	twodigits = value % 100; 

	if ((twodigits == 11) || (twodigits == 12) || (twodigits == 13)) {
	switch ( value % 100) {

		case 11: case 12: case 13:

		printf("%dth\n", value);

		break;

	}
	}

	else {
	digit = ( value % 10 ); 

	if ( digit == 1) {

		printf("%dst\n", value);

	}

	else if ( digit == 2) {

		printf("%dnd\n", value);

	}

	else if ( digit == 3) {

		printf("%drd\n", value);

	}

	else {

		printf("%dth\n", value);

	}
}
}


