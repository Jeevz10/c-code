// prize.c
#include <stdio.h>
#define MAX_SIZE 300

typedef struct {
	int id; // The student number
	int scores[MAX_SIZE]; // The test scores of the student
	int prize; // Whether the student has received a prize
} student_t;

void scanScores(student_t [],int,int);
void printScores(student_t [],int [],int,int);
void determinePrize(student_t [],int [],int,int);
int main(void){
	int weeks,students,prize[MAX_SIZE];
	student_t class[MAX_SIZE];
	
	printf("Enter number of students: ");
	scanf("%d",&students);

	printf("Enter number of weeks: ");
	scanf("%d",&weeks);

	scanScores(class,students,weeks);

	determinePrize(class,prize,students,weeks);

	printScores(class,prize,students,weeks);
	return 0;
}

void scanScores(student_t class[],int students,int weeks) {
	int i,j;

	printf("Enter scores:\n");
	for (i = 0;i < students;i++) {
		class[i].id = i;
		for (j = 0;j < weeks;j++) {
			scanf("%d",&class[i].scores[j]);
		}
	}
}

void printScores(student_t class[],int prize[],int students,int weeks) {
	int i,j;
/*
	for (i = 0;i < students;i++) {
		for (j = 0; j < weeks;j++) {
			printf("%d ",class[i].scores[j]);
		}
		printf("\n");
	}
*/	
	printf("The prize sequence is:\n");

	for (i = 0;i < weeks;i++) {
		printf("%d ",prize[i]);
	}
	printf("\n");
}

void determinePrize(student_t class[],int prize[],int students,int weeks) {
	int i = 0,j = 0,k = 0,max = 0,index,can = 0;

	for(i = 0;i < weeks;i++) {
		max = 0;
		
		for(j = 0;j < students;j++) {
			can = 0;
			for(k = 0;k < i;k++) {

				if ( j == prize[k] - 1) {
					can = 1;
				}
			}

			if (can == 1) {
				continue;
			}
//			printf("%d",max);
			if (class[j].scores[i] > max) {
				max = class[j].scores[i];
				index = j + 1;
			}
			
		}
		prize[i] = index;
//		printf("%d\n",prize[i]);
	}
}



