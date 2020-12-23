#include <stdio.h>
#include <math.h>

int luckydraw(int, int, int);
int main(void) {
	int factor,musthave,numofpart,numofwinners;

	printf("Enter factor-digit: ");
	scanf("%d", &factor);

	printf("Enter must-have-digit: ");
	scanf("%d", &musthave);

	printf("Enter number of participants: ");
	scanf("%d", &numofpart);

	numofwinners = luckydraw(factor,musthave,numofpart);

	printf("Number of winners: %d\n", numofwinners);

	return 0;
}

int luckydraw(factor,musthave,numofpart) {
	int limit,num,sum = 0,counter = 1, digit;

	limit = numofpart / factor;

	for (counter = 1; counter <= limit; counter++) {

		num  = counter * factor;
		while (num != 0) {
			digit = num % 10;
			if (digit == musthave) {
				sum += 1;
				break;
			}
			num = num /10;
		}
	}
	return sum;
}

