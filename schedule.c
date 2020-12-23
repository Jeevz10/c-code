// schedule.c
// This program reads a schedule of lessons, and computes
// the longest lesson, the number of free periods, and the
// most number of concurrent lessons.
// This is a skeleton program for students.

#include <stdio.h>
#define MAX_INTERVALS 20
#define LATEST_FINISH 1000

typedef struct {
	int start, finish;
} interval_t;

void print_intervals(interval_t [], int) ;
void scan_intervals(interval_t [],int);
int longest_lesson(interval_t [],int);
void sort_lesson(interval_t intervals[],int);
int free_periods(interval_t [],int);
int concurrents(interval_t [],int);
int main(void) {
	int n; // number of intervals
	interval_t intervals[MAX_INTERVALS];
	int duration,periods,concurrent;

	printf("Enter number of intervals: ");
	scanf("%d", &n);

	scan_intervals(intervals,n);

	duration = longest_lesson(intervals,n);

	sort_lesson(intervals,n);
 	
	periods = free_periods(intervals,n);
	
	concurrent = concurrents(intervals,n);

	printf("%d\n",periods);
	printf("%d\n",concurrent);

//	print_intervals(intervals,n);
	return 0;
}

// Print the interval array arr
void print_intervals(interval_t intervals[], int size) {
	int i;

	for (i=0; i<size; i++) 
		printf("%d %d\n", intervals[i].start, intervals[i].finish);
}

void scan_intervals(interval_t intervals[],int size) {
	int i;

	for (i = 0;i < size;i++) {
		scanf("%d %d",&intervals[i].start,&intervals[i].finish);
	}
}

int longest_lesson(interval_t intervals[],int size) {
	int i, max = 0;

	for (i = 0;i < size;i++) {
		if ((intervals[i].finish - intervals[i].start) > max) {
			max = intervals[i].finish - intervals[i].start;
		}
	}
	return max;
}

void sort_lesson(interval_t intervals[],int size) {
	int start = 0,min_index,i;
	interval_t temp;

	for (start = 0;start < size - 1;start++) {
		min_index = start;

		for (i = start + 1;i < size;i++) {
			if (intervals[i].start < intervals[min_index].start) {
				min_index = i;
			}
		}

		temp = intervals[start];
		intervals[start] = intervals[min_index];
		intervals[min_index] = temp;
	}
}

int free_periods(interval_t intervals[],int size) {
	int i,finish,periods = 0;
	
	finish = intervals[0].finish;

	for (i = 1;i < size;i++) {
		if (intervals[i].start < finish) {
			if (intervals[i].finish > finish) {
				finish = intervals[i].finish;
			}
		}
		else if (intervals[i].start >= finish) {
			finish = intervals[i].finish;
			periods++;
		}
	}
	return periods;
}

int concurrents(interval_t intervals[],int size) {
	int i = 0,j,max = 0,count = 0,lower,upper;

	for (i = 0;i < size;i++) {

		lower = intervals[i].start;
		upper = intervals[i].finish;

		for (j = 0 ;j < size;j++) {
			
			if (j == i) {
				continue;
			}

			if (intervals[j].start >= lower && intervals[j].finish <= upper) {
				count++;
			}
		}

		if (count > max) {
			max = count;
		}
		count = 0;
	}
	return max;
}
