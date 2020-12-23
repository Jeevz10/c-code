// switch_to_if.c
// To convert switch statement into if statement.
#include <stdio.h>

int main(void) {
	int score;
	char grade;

	printf("Enter score: ");
	scanf("%d", &score);

	switch (score) {
		case 10: 
		case 9:
		case 8:	 grade = 'A'; break;
		case 7:	
		case 6:	 grade = 'B'; break;
		case 5:  grade = 'C'; break;
		default: grade = 'F';
	}
	printf("Grade is %c.\n", grade);

	return 0;
}

