// health_screen.c
#include <stdio.h>

#define MAX_READINGS 50   // maximum number of readings

typedef struct {
	float score; // the health score
	int   freq;  // how many people with that score
} reading_t;

int scanReadings(reading_t []);
void printReadings(reading_t [], int);
int duplicate(reading_t [],int);

int main(void) {
	reading_t readings[MAX_READINGS];  
	int size,dupli;
	
	printf("Enter score and frequency (end with 0 0):\n");
	size = scanReadings(readings);
	// printReadings(readings, size); // for checking
	
	dupli = duplicate(readings,size);

	printf("Number of unique readings = %d\n",dupli);

	return 0;
}

int scanReadings(reading_t readings[]) {
	int size = 0,i = 0;

	for (i = 0;i < MAX_READINGS;i++) {
		scanf("%f %d",&readings[i].score,&readings[i].freq);
		
		if (readings[i].score == 0.0 && readings[i].freq == 0) {
			break;
		}

		size++;
	}
	return size;
}
// Print array arr
void printReadings(reading_t arr[], int size) {
	int i;

	for (i=0; i<size; i++) 
		printf("%f %d\n", arr[i].score, arr[i].freq);
}

int duplicate(reading_t readings[],int size) {
	int i = 0,j = 0,unique = 0;

	for (i = 0;i < size;i++) {
		if (readings[i].score == 0.0) {
			continue;
		}
		for (j = i + 1;j < size;j++) {
			if (readings[i].score == readings[j].score) {
				readings[j].score = 0.0;
			}
		}
		readings[i].score = 0.0;
		unique++;
	}

	return unique;
}


	
