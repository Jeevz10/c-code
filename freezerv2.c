#include <stdio.h>
#include <math.h>

int main(void) {
	int hours, minutes;
	float time, temperature;

	printf("Enter hours and minutes since power failure: ");
	scanf("%d %d", &hours, &minutes);

	time = (hours + ((float)minutes/60));

	temperature = (((4 * pow(time,10))/((pow(time,9))+2))-20);

	printf("Temperature in freezer = %.2f\n", temperature);

	return 0;

}
