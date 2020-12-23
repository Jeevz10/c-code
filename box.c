/**
* CS1010 AY2017/8 Semester 1 Lab1 Ex2
* box.c
* This program computes the surface area and the diagonal that connects the two vertices 
* that are furthest apart in  box, when given the length, width and height of the box.
* Jeevan Neralakere Somashekhar 
* C04
*/ 

#include <stdio.h>
#include <math.h>

int compute_surface_area(int,int,int); // Function prototype of the function compute_surface_area 
double compute_diagonal(int,int,int);  // Function prototype of the function compute_diagonal 
int main(void) {
	int length, width, height, surfacearea;
	float diagonal;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width : ");
	scanf("%d", &width);

	printf("Enter height: ");
	scanf("%d", &height);

	surfacearea = compute_surface_area(length,width,height); // Using this function, return the values into the variable surfacearea
	diagonal = compute_diagonal(length,width,height); // Using this function, return the values into the variable diagonal  

	printf("Surface area = %d\n",surfacearea);
	printf("Diagonal = %.2f\n",diagonal);

	return 0;

}
// Function definition of compute_surface_area
int compute_surface_area(int length, int width, int height) {
	int surfacearea; // Declare new variable surfacearea
	surfacearea = ((2 * (width * length)) + (2 * (width * height)) + (2 * (length * height))); // Calculate surface area by using the equation 
	return surfacearea;
}
// Function definition of compute_diagonal 
double compute_diagonal(int length, int width, int height) {
	int intermediate; // Declare new variable intermediate
	double diagonal; // Declare new variable diagonal 
	intermediate = ((pow(width,2)) + (pow(length,2))); // This variable stores temporary information in the intermediate step 
	diagonal = (sqrt((pow(height,2)) + (intermediate))); // Calculate the length of the diagonal using the equation 
	return diagonal;
}
