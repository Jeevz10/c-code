// cap.c
// Read a student's results and compute his CAP.
// This is a skeleton program for students.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_MODULES 50

typedef struct {
	char module[8],grade[3];
	int MCs;
} result_t;

typedef struct {
	char name[30];
	result_t results[50];
} student_t;

void scan_results(student_t *,int);
void print_results(student_t, int);
float compute_cap(student_t, int);

int main(void) {
	student_t students;
	int num_modules;

	printf("Enter student's name: ");
	fgets(students.name,31,stdin);

	if (students.name[strlen(students.name) - 1] == '\n') {
		students.name[strlen(students.name) -1] = '\0';
	}

//	printf("%s",students.name);

	printf("Enter number of modules taken: ");
	scanf("%d",&num_modules);

	printf("Enter results of %d modules:\n", num_modules);
	scan_results(&students,num_modules);

	print_results(students, num_modules); // for checking

	printf("CAP = %.2f\n", compute_cap(students, num_modules));

	return 0;
}

void scan_results(student_t *students,int size) {
	int i = 0;

	for (i = 0;i < size;i++) {
		scanf("%s %s %d",students->results[i].module,students->results[i].grade,&(students->results[i]).MCs);
		getchar();
	}
}
void print_results(student_t students, int num_modules) {
	int i;

	printf("Student's name: %s\n", students.name);
	for (i=0; i<num_modules; i++)
		printf("%s %s %d\n", students.results[i].module,
				students.results[i].grade, students.results[i].MCs);
}

// Compute CAP of student.
// This is a stub.
float compute_cap(student_t students, int num_modules) {
	int CAP = 0,i = 0;
	float sum = 0.0,sum2 = 0.0;

	for (i = 0;i < num_modules;i++) {
		
		if ((strcmp(students.results[i].grade,"A+") == 0) || (strcmp(students.results[i].grade, "A") == 0)) {
			sum += students.results[i].MCs * 5;
			sum2 += students.results[i].MCs;
		}
		else if (strcmp(students.results[i].grade, "A-") == 0) {
			sum += students.results[i].MCs * 4.5;
			sum2 += students.results[i].MCs;
		}
		else if (strcmp(students.results[i].grade,"B+") == 0) {
			sum += students.results[i].MCs * 4;
			sum2 += students.results[i].MCs;
		}
		else if (strcmp(students.results[i].grade,"B") == 0) {
			sum += students.results[i].MCs * 3.5;
			sum2 += students.results[i].MCs;
		}
		else if (strcmp(students.results[i].grade,"B-") == 0) {
			sum += students.results[i].MCs * 3;
			sum2 += students.results[i].MCs;
		}
		else if (strcmp(students.results[i].grade,"C+") == 0) {
			sum += students.results[i].MCs * 2.5;
			sum2 += students.results[i].MCs;
		}
		else if(strcmp(students.results[i].grade, "C") == 0) {
			sum += students.results[i].MCs * 2;
			sum2 += students.results[i].MCs;
		}
		else if(strcmp(students.results[i].grade,"D+") == 0) {
			sum += students.results[i].MCs * 1.5;
			sum2 += students.results[i].MCs;
		}
		else if(strcmp(students.results[i].grade, "D") == 0) {
			sum += students.results[i].MCs * 1;
			sum2 += students.results[i].MCs;
		}
		else if(strcmp(students.results[i].grade,"F") == 0) {
			sum += students.results[i].MCs * 0;
			sum2 += students.results[i].MCs;
		}
	}

	CAP = sum / sum2;

	return CAP;
}

