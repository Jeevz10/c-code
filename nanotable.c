/**
 * CS1010 AY2017/18 Semester 1 Lab2
 * Nanotable0.c
 * This is a data storage system for exam records.
 * It allows user to insert exam scores and do basic analysis.
 * This particular program contains just the fundamental features
 * such as calculating the sum and average of a given number of integers.
 * Jeevan Neralakere Somashekhar 
 * C04
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define COMMAND_HELP 0
#define COMMAND_EXIT 1
#define COMMAND_SUM 2
#define COMMAND_AVE 3
#define COMMAND_INVALID 4

/* Function prototypes */
int parse_command();

int check_command(char* input);

void print_help();

int simple_sum();

int simple_average();

int main() {
	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	parse_command();

	return 0;
}
// This function works in a REPL style
int parse_command() {
	char tmp_command[100] = "";
	int command_code;

// The user input will be directed to the check_command(tmp_command) function.
// Here it will assign various values to the different types of commands
// Namely the commands are "help","exit","sum","ave"
// The do { } while () function is to execute the various functions till the user inputs exit.
// The parse command function will run things by assigning the various tasks to the respective functions 
	do {
		
	printf("Waiting for command...\n");
	scanf("%s", tmp_command);

	command_code = check_command(tmp_command);    

	if (command_code == COMMAND_HELP) {
		print_help();
	}
	else if (command_code == COMMAND_EXIT) {
		printf("See you!\n");
	}
	else if (command_code == COMMAND_SUM) {
		simple_sum();
	}
	else if (command_code == COMMAND_AVE) {
		simple_average();
	}
	else {
		// others
		printf("No such command: %s, please input command again!\n", tmp_command);
	}

 } 	while ( command_code != COMMAND_EXIT); 

	return 0;
}
// This function is to calculate the sum of integers 
int simple_sum() {
	// Initialize sum to 0 and counter to 1. The variable "counter" is 
	// to count the  number of integers input by the user
	// The variable "tempvariable" is to store integers temporarily
	// The variable "sum" stores the value of the sum of integers
	int sum = 0, tempvariable, num_of_int, counter = 1;
	// User inputs the number of integers he/she wants to find the sum of
	printf("Please indicate the number of integers:\n");
	scanf("%d", &num_of_int);
	// Starting from one, we will print a statement that asks for user input
	// The number that is input, will be stored as in the variable "tempvariable"
	// Immediately, this number stored in "tempvariable" will be added to the variable "sum"
	for ( counter = 1; counter <= num_of_int; counter++) {
		// For the numbers 11,12,13, the suffix of these numbers ends with a -th and not
		// with a -st or -nd or -rd as commonly seen in other numbers that has the number 
		// 1, 2 or 3 in the ones place. Thus, we identify and seperate these statements out 
		// such that we output grammatically correct statements.
		if ( ( counter == 11) || ( counter == 12) || ( counter == 13) ) {
			printf("Please input the %dth number:\n", counter);
			scanf("%d", &tempvariable);
			sum += tempvariable;
		}
		else if ( ( counter % 10) == 1 ) {
			printf("Please input the %dst number:\n", counter);
			scanf("%d", &tempvariable);
			sum += tempvariable;
		}
		else if ( ( counter % 10) == 2) {
			printf("Please input the %dnd number:\n", counter);
			scanf("%d", &tempvariable);
			sum += tempvariable;
		}
		else if ( ( counter % 10) == 3) {
			printf("Please input the %drd number:\n", counter);
			scanf("%d", &tempvariable);
			sum += tempvariable;
		}
		else {
			printf("Please input the %dth number:\n", counter);
			scanf("%d", &tempvariable);
			sum += tempvariable;
		}
	}
	printf("sum is %d\n", sum);
	return 0;
}

// This function is to calculate the average of the integers input by the user
int simple_average() {
	// Initialize sum to 0 and counter to 1. The variable "counter" is 
	// to count the  number of integers input by the user
	// The variable "tempvariable" is to store integers temporarily
	// The variable "sum" stores the value of the sum of integers
	// The variable "average" stores the average of the integers
	int sum = 0, tempvariable, num_of_int, counter = 1;
	float average;
	// User inputs the number of integers he/she wants to find the average of
	printf("Please indicate the number of integers:\n");
	scanf("%d", &num_of_int);
	// Starting from one, we will print a statement that asks for user input
	// The number that is input, will be stored as in the variable "tempvariable"
	// Immediately, this number stored in "tempvariable" will be added to the variable "sum"
	for ( counter = 1; counter <= num_of_int; counter++) {
		// For the numbers 11,12,13, the suffix of these numbers ends with a -th and not
		// with a -st or -nd or -rd as commonly seen in other numbers that has the number 
		// 1, 2 or 3 in the ones place. Thus, we identify and seperate these statements out 
		// such that we output grammatically correct statements.
		if ( ( counter == 11) || ( counter == 12) || ( counter == 13) ) {
			printf("Please input the %dth number:\n", counter);
			scanf("%d", &tempvariable);
			sum += tempvariable;
		}
		else if ( ( counter % 10) == 1 ) {
			printf("Please input the %dst number:\n", counter);
			scanf("%d", &tempvariable);
			sum += tempvariable;
		}
		else if ( ( counter % 10) == 2) {
			printf("Please input the %dnd number:\n", counter);
			scanf("%d", &tempvariable);
			sum += tempvariable;
		}
		else if ( ( counter % 10) == 3) {
			printf("Please input the %drd number:\n", counter);
			scanf("%d", &tempvariable);
			sum += tempvariable;
		}
		else {
			printf("Please input the %dth number:\n", counter);
			scanf("%d", &tempvariable);
			sum += tempvariable;
		}
	}
	// Calculate the average of the integers by dividing the sum of integers by the number of integers 
	average = ((float)sum / num_of_int);
	// Round up or down the value stored in the variable "average" by implying a round() function.
	printf("average is %.0f\n", round(average));
	return 0;
}

// DO NOT MODIFY THE FOLLOWING PART!

// This function takes a command as input and returns an integer as output.
/* INPUT    OUTPUT
   help     0
   EXIT     1
   SUM      2
   AVE      3
   others   4
 */
int check_command(char* input) {
	if (strcmp(input,"help") == 0) {
		return COMMAND_HELP;
	}
	else if (strcmp(input,"exit") == 0) {
		return COMMAND_EXIT;
	}
	else if (strcmp(input,"sum") == 0) {
		return COMMAND_SUM;      
	}
	else if (strcmp(input,"ave") == 0) {
		return COMMAND_AVE;
	}
	else {
		return COMMAND_INVALID;
	}
}

// This function prints the help information
void print_help() {
	printf("Commands available: sum, ave, help, exit\n");
}

