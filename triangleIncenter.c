// triangleIncenter.c
// This program computes the incenter of a triangle
// given the coordinates of three vertices.
#include <stdio.h>
#include <math.h>

void incenter(float,float,float,float,float,float,float *,float *);
int main(void) {
	float x1, y1,    // coordinates of 1st vertex
				x2, y2,    // coordinates of 2nd vertex
				x3, y3,    // coordinates of 3rd vertex
				xIn, yIn;  // coordinates of incenter


	printf("Coordinates of 1st vertex: ");
	scanf("%f %f", &x1, &y1);
	printf("Coordinates of 2nd vertex: ");
	scanf("%f %f", &x2, &y2);
	printf("Coordinates of 3rd vertex: ");
	scanf("%f %f", &x3, &y3);

	incenter(x1,y1,x2,y2,x3,y3,&xIn,&yIn);

	printf("Coordinates of incenter = (%.2f, %.2f)\n", xIn, yIn);

	return  0;
}

void incenter(float x1,float y1,float x2,float y2,float x3,float y3,float *xIn_ptr,float *yIn_ptr) {
	float p,a,b,c;

	a = pow(pow((x3-x2),2)+pow((y3-y2),2),0.5);
	b = pow(pow((x3-x1),2)+pow((y3-y1),2),0.5);
	c = pow(pow((x2-x1),2)+pow((y2-y1),2),0.5);

	p = a + b + c;

	*xIn_ptr = ((a * x1) + (b * x2) + (c * x3)) / p;
	*yIn_ptr = ((a * y1) + (b * y2) + (c * y3)) / p;
}



