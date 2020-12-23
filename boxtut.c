/**
 * box.c 
 * This program calculates the surface area of a box, and the
 * length of the diagonal connecting two vertices farthest apart.
 */

#include <stdio.h>
#include <math.h>

void compute(int, int, int,int *,double *);

int main(void) {
	int length, width, height, area,*area_ptr = &area;
	double diagonal,*diagonal_ptr = &diagonal;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter height: ");
	scanf("%d", &height);

	compute(length, width, height,&area,&diagonal);
	printf("Surface area = %d\n", area);

	printf("Diagonal = %.2f\n", diagonal);

	return 0;
}

// Compute the length of diagonal of a box between two vertices
// that are farthest apart.
// Precond: length>0, width>0, height>0
void compute_diagonal(int length, int width, int height,int *area_ptr,double *diagonal_ptr) {
	*diagonal_ptr = sqrt((length * length) + (width * width) + (height * height));
	*area_ptr = (2 * ((length * width) + (width * height) + (length * height)));
}

