#include <stdio.h>
#include <math.h>

float speed_of_sound(float);

int main(void) {
	float temperature, speed;

	printf("Temperature in degree Fahrenheit: ");
	scanf("%f", &temperature);

	speed = speed_of_sound(temperature);

	printf("Speed of sound in air of %.2f degree = %.2f ft/sec\n", temperature, speed);

	return 0;

}

float speed_of_sound(float temperature) {
	
	float speed;
	speed = (1086*(sqrt(((5 * temperature) + 297) / 247)));

	return speed;
}










