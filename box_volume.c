
/** 
* CS1010 AY2017/18 Semester 1 Lab0 Ex1 
* box_volume.c
* This program calculates the volume of a box.
* Jeevan NS
* C04
*/ 

#include <stdio.h>

int main(void) {

	int length, width, height, volume;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width : ");
	scanf("%d", &width);

	printf("Enter height: ");
	scanf("%d", &height);
	
	volume = length * width * height;

	printf("Volume = %d\n", volume);

	return 0; 
}
