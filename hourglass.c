/* hourglass.c
 * This program reads the durations of 2 hourglasses and a duration to measure,
 * to find the number of times to flip the hourglasses so that the total
 * number of flips is minimum.
 */

#include <stdio.h>
#include <limits.h> 

// Given function prototype must not be changed
int compute_flips(int, int, int, int *, int *);

int main (void) {
	int hg1, hg2;        // durations of hourglasses; assume hg1 < hg2
	int time;            // duration to measure; assume hg2 < time
	int flips1, flips2;  // number of flips needed for hourglasses

	printf("Enter 3 inputs: ");
	scanf("%d %d %d", &hg1, &hg2, &time);
	
	if (compute_flips(hg1,hg2,time,&flips1,&flips2)) {
		printf("Possible!\n");
//		printf("%d %d %d\n",hg1,hg2,time);
		printf("%d flip(s) for %d-minute hourglass and %d flip(s) for %d-minute hourglass.\n",flips1,hg1,flips2,hg2);
	}
	else {
		printf("Impossible!\n");
	}
	return 0;
}

int compute_flips(int hg1,int hg2,int time,int *flips1,int *flips2) {
	int limit1,limit2,a1,b1,a2,b2,temp1 = INT_MAX,temp2 = INT_MAX,i = 0,j = 0;

	limit1 = (time / hg1);
	limit2 = (time / hg2);

	for (i= 0;i <= limit1;i++) {
		for (j = 0;j <= limit2;j++) {
			if ((hg1 * i) + (hg2 * j) == time) {
				if (i + j < temp1) {
					temp1 = i + j;
					a1 = i;
					b1 = j;
				}
			}
		}
	}/*
	if (temp1 != 0) {
		*flips1 = a1;
		*flips2 = b1;
		return 1;
	}
	else {
		return 0;
	}*/

	if ((a1 == 0) && (b1 == 0)) {
		return 0;
	}
	else {
		*flips1 = a1;
		*flips2 = b1;
		return 1;
	}
/*
	for (i = 0;i <= limit2;i++) {
		for (j = 0;j <= limit1;j++) {
			if ((hg2 * i) + (hg1 * j) == time) {
				if (i + j < temp2) {
					temp2 = i + j;
					a2 = j;
					b2 = i;
				}
			}
		}
	}
	if (temp2 != 0) {
	}
	else {
		temp2 = 0;
	}
	if ((temp1 == 0) && (temp2 == 0)) {
		return 0;
	}
	if ((temp1 == 0) && (temp2 != 0)) {
		*flips1 = a2;
		*flips2 = b2;
		return 1;
	}
	if ((temp2 == 0) && (temp1 != 0)) {
		*flips1 = a1;
		*flips2 = b1;
		return 1;
	}
	if ((temp1 < temp2)) {
		*flips1 = a1;
		*flips2 = b1;
		return 1;
	}
	if (temp2 <  temp1) {
		*flips1 = a2;
		*flips2 = b2;
		return 1;
	}
	if (temp2 == temp1) {
		*flips1 = a1;
		*flips2 = b1;
		return 1;
	}
	*/
}



