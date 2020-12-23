/**
* CS1010 AY2017/8 Semester 1 Lab1 Ex1
* invest.c
* This program calculates the final amount when given the principal amount,
* interest rate, and the number of years, based on compound interest.
* Jeevan Neralakere Somashekhar 
* C04
*/

#include <stdio.h>
#include <math.h>

int main(void) {
	int principal, rate, numYears;
	float moneyEarned; // 

	printf("Enter principal amount: ");
	scanf("%d", &principal);

	printf("Enter interest rate   : ");
	scanf("%d", &rate);

	printf("Enter number of years : ");
	scanf("%d", &numYears);

// Compute the amount earned by using the given equation
// Since rate is of an integer type, typecast it to be a float such that the value computed will be a float
	moneyEarned = (((principal * (1 - (pow(((float)rate/100),(numYears + 1))))) / ( 1 - ((float)rate/100))));

	printf("Amount = $%.2f\n", moneyEarned);
	return 0;
}
