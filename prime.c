#include <stdio.h>
#include <math.h>

void is_prime(int);

int main(void) {
	
	int usernum;

	printf("Enter a positive integer: ");
	scanf("%d", &usernum);

	if ( usernum == 1) {

		printf("1 is not a prime.\n");
	}

	else {
	is_prime(usernum);
}
	return 0;

}

void is_prime( int usernum) {

	int counter = 2, check, haha;

	for ( counter = 2; counter < usernum; counter++) {

		haha = usernum % counter;

		if ( haha == 0 ) {

			check = 3;
			break;
		}

	}

	if ( check == 3) {

	printf("%d is not a prime.\n", usernum);

	}

	else {

		printf("%d is a prime.\n", usernum);
	}
}



