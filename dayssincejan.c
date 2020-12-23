#include <stdio.h>
#include <math.h>

int computedays( int, int);

int main(void) {

	int day, days, month; 

	printf("Enter day and month: ");
	scanf("%d %d", &day, &month);

	days = computedays( day, month);
	
	printf("Day %d of month %d is the %dth day of 2017.\n", day, month, days);

	return 0;

}

int computedays( int day, int month) {
	
	int days;

	switch ( month ) {

		case 1:

		days = day;

		break;

		case 2:

		days = ( 31 + day);

		break;

		case 3:

		days = ( 31 + 28 + day);

		break;

		case 4:

		days = ( 31 + 28 + 31 + day);

		break;

		case 5:

		days = ( 31 + 28 + 31 + 30 + day);

		break;

		case 6:

		days = ( 31 + 28 + 31 + 30 + 31 + day);

		break;

		case 7:

		days = ( 31 + 28 + 31 + 30 + 31 + 30 + day);

		break;

		case 8:

		days = ( 31 + 28 + 31 + 30 + 31 + 30 + 31 + day);

		break;

		case 9:

		days = ( 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day);

		break;

		case 10:

		days = ( 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day);

		break;

		case 11:

		days = ( 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day);

		break;

		case 12:

		days = ( 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day);

		break;
}

	return days;

}


