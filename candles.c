/**
 * CS1010 AY2017/8 Semester 1 Lab3 Ex1
 * candles.c
 * This is a program that helps Alexandra to find out how many candles he can
 * burn in total. 
 * Jeevan Neralakere Somashekhar 
 * C04
 */

#include <stdio.h>
#include <math.h>

int count_candles(int,int); /* Function prototype. This function is used to count the total number of candles burnt.*/

int main(void) {
/* The variable "numcandles" refers to the number of candles input by the user.
 * The variable "residual" refers to the number of candles needed to make a new candle.
 * The variable "total_burnt" refers to the total number of candles burnt.*/
	int numcandles, residuals, total_burnt;

	printf("Enter number of candles and \n");
	printf("number of residuals to make a new candle: ");
	scanf("%d %d",&numcandles,&residuals);
/* The user inputs will be passed to the function "count_candles", which
    will return the total number of candles burnt.*/
	total_burnt = count_candles(numcandles,residuals);

	printf("Total candles burnt = %d\n",total_burnt);

	return 0;
}
  /*This function returns the total number of candles burnt.*/
int count_candles(int numcandles,int residuals) {
	 /* The variable "sum" stores the number of candles burnt
	  * The variable "leftover" stores the number of leftover candles that could not be rolled up into new candles when it is burnt 
	  *	The variablle "total_burnt" stores the total number of candles burnt after burning the leftover candles that could
	  * not be rolled up into new candles*/
	int sum = 0, total_burnt, leftover;

	do {
	 /*(numcandles / residuals) is the number of new candles that can be rolled up 
	  *(numcandles % residuals) is the initial number of candles not burnt initially*/
		sum += (numcandles - (numcandles % residuals));
		numcandles = ((numcandles / residuals) + (numcandles % residuals));

		if (numcandles < residuals) {
			leftover = numcandles;
		}
	}
	while (numcandles >= residuals);

	total_burnt = (sum + leftover);

	return total_burnt;
}
		


