#include <stdio.h>
#include <math.h>

int printcentury(int);
int printordinal(int);

int main(void) {
	int userinput, century, ordinaltype;

	printf("Enter year: ");
	scanf("%d", &userinput);

	century = printcentury(userinput);
	ordinaltype = printordinal(century);

	switch (ordinaltype) {

		case 1: 
		printf("The year %d falls in the %dth century.\n", userinput, century);
		break;

		case 2:
		printf("The year %d falls in the %dst century.\n", userinput, century);
		break;

		case 3:
		printf("The year %d falls in the %dnd century.\n", userinput, century);
		break;

		case 4:
		printf("The year %d falls in the %drd century.\n", userinput, century);
		break;

		case 5:
		printf("The year %d falls in the %dth century.\n", userinput, century);
	}

	return 0;
}

int printcentury(int userinput) {
	int century;

	century = (userinput / 100) + 1;
	return century;
}

int printordinal(int century) {
	int ordinaltype;

	if (((century % 100)== 11) || ((century % 100)== 12) || ((century % 100)== 13)) {
		ordinaltype = 1;
	}
	else if ((century % 10)== 1) {
		ordinaltype = 2;
	}
	else if ((century % 10)== 2) {
		ordinaltype = 3;
	}
	else if ((century % 10)== 3) {
		ordinaltype = 4;
	}
	else {
		ordinaltype = 5;
	}
	return ordinaltype;
}




	
