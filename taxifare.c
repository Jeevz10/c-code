#include <stdio.h>
#include <math.h>

float computefare( int, int, int);

int main(void) {

	int daytype, boardhours, boardminutes, boardtime, distance;
	float taxifare;

	printf("Day type: ");
	scanf("%d", &daytype);

	printf("Boarding hour and minute: ");
	scanf("%d %d", &boardhours, &boardminutes);

	printf("Distance: ");
	scanf("%d", &distance);

	boardtime = ((boardhours * 60) + boardminutes);

	taxifare = computefare( daytype, boardtime, distance);

	printf("Boarding time is %d minutes\n", boardtime);
	printf("Total taxi fare is $%.2f\n", taxifare);

	return 0;

}

float computefare( int daytype, int boardtime, int distance) {
	
	int distance_2 = 0, distance_3 = 10200, counter = 1000, counter_2 = 0;
	float taxifare = 3.18, taxifare_2 = 0;
	/* if ( distance <= 1000) {

		taxifare = 3.40;
	}

	if ( distance <= 10200) {

		taxifare = ( 3.40 + ((( (float)distance - 1000) / 400) * 0.22));
		xi = 

	}

	else if ( distance > 10200) {

		taxifare = ( 3.40 + ((( (float)distance - 1000) / 400) * 0.22) + ((( (float)distance - 10200) / 350) * 0.22));
		 
		
	}
 */
 
 	if ( distance > 10200) {
		
		distance_2 = (distance - 10200);
	}

		if ( distance > 1000) {

			if ( distance <= 10200) {
		
		for ( counter = 1000; counter <= distance; counter += 400) 
		{
			
			taxifare += 0.22;
		}
}
			else {
			
			for ( counter = 1000; counter <= distance_3; counter += 400) {

				taxifare += 0.22;
			}

			for ( counter_2 = 0; counter_2 <= distance_2; counter_2 +=350) 
		{
			
			taxifare_2 += 0.22;
		}

			taxifare += taxifare_2;
		}
}
	else {
			taxifare += 0.22;
		}

		if ( daytype == 0) {

		if ( boardtime < 360) {

			taxifare = ( taxifare * 1.5);
		}

		else if ( boardtime < 1080) {

			taxifare = taxifare;
		}

		else if ( boardtime < 1440) {

			taxifare = ( taxifare * 1.25);

		}
	}

	else if ( daytype == 1) {

		if ( boardtime < 360) {

			taxifare = ( taxifare * 1.5);

		}

		else if ( boardtime < 1080) {

			taxifare = ( taxifare * 1.25);

		}

		else if ( boardtime < 1440) {

			taxifare = ( taxifare * 1.25);

		}
		
		} 

		return taxifare;	
}
