/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex3
 * bisection.c
 * Jeevan Neralakere Somashekhar 
 * C04
 * This program computes the root of a continuous function, using the bisection method.
 */

#include <stdio.h>
#include <math.h>
#define THRESHOLD 0.0001

/* Function prototype of the function polynomial.*/
double polynomial( double, int, int, int, int);

int main(void) {
	int    c3, c2, c1, c0; /* coefficients of polynomial*/
	double a, b, pA, pB, m, pM, root, pR;          
	/* a and b are  endpoints, pA and pB are function values of the endpoints, m is the midpoint, pM is the function value of the midpoint, 
	 * root is the root of the function and pR is the function value of the root.*/

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d",&c3,&c2,&c1,&c0);

	printf("Enter endpoints a and b: ");
	scanf("%lf %lf",&a,&b);
	/* This do-while iteration loop narrows down the values of a and b to the point that either the function of the midpoint of the endpoints are 0 or 
	 * the threshold between the endpoint values are lesser than 0.0001.*/  
	do {
	pA = polynomial(a,c3,c2,c1,c0);
	pB = polynomial(b,c3,c2,c1,c0);

	m = (( a + b) / 2);
	pM = polynomial(m,c3,c2,c1,c0);
	/* This do-while loop stops when either pM = 0 or the threshold between the endpoints is lesser than 0.0001.*/
	if ((pM == 0) || (((fabs(a - b)) <= THRESHOLD)) || ((fabs(b - a)) <= THRESHOLD)) {
		break;
	}
	/* After calculating pM, we compare the signs of pM with both pA and pB. If either pA or pB has the same sign as 
	 * pM, then midpoint value,m, will replace either a or b respectively. This process will carry on till the aforementioned 
	 * criterias are met.*/
	else if (pM > 0) {
		if (pA > 0) {
			a = m;
			continue;
		}
		else  {
			b = m;
			continue;
		}
	}
	else {
		if (pA < 0) {
			a = m;
			continue;
		}
		else {
			b = m;
			continue;
		}
	}
	}
	while (((fabs(a - b)) > THRESHOLD) || (((fabs(b - a)) > THRESHOLD )));/* This loop will carry on so as long the distance between a and b is more than the threshold.*/
	/* When the distance between a and b is met, the root value or rather, the mid point is caluclated. This root value is passed to the polynomial function for calculation.*/
	root = ((a + b) / 2); 
	pR = polynomial(root,c3,c2,c1,c0);

	printf("root = %.6lf\n", root);
	printf("p(root) = %.6lf\n", pR);

	return 0;
}
/* This function calculates the function value of the respective points of a continuous function.*/
double polynomial(double xvalue,int c3,int c2,int c1,int c0){
	double function_value;
	/* function value is calculated as c3x^3 + c2x^2 + c1^x + c0.*/ 
	function_value = ((c3 * pow(xvalue,3)) + (c2 * pow(xvalue,2)) + (c1 * pow(xvalue,1)) + (c0));

	return function_value;
}


