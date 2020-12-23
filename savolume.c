// box.c
// To compute the number of boxes with length, width and height
// in the range [lower,upper] whose surface area is larger than
// volume.
#include <stdio.h>

int box(int,int);
int main(void) {
	int lower, upper,sum;

	printf("Enter lower and upper limits: ");
	scanf("%d %d", &lower, &upper);
	
	sum = box(lower,upper);
	
	printf("Answer = %d\n",sum);

	return 0;
}

int box(int lower,int upper) {
	int sum = 0,sa,vol,l,w,h;

	for (l = lower;l < upper;l++) {
		for (w = lower;w < upper;w++) {
			for (h = lower;h < upper;h++) {
				vol = l * w * h;
				sa = (2 * l * w) + (2 * l * h) + (2 * w * h);

				if (sa >= vol) {
					sum++;
				}
			}
		}
	}
	return sum;
}

