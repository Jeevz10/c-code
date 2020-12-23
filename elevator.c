/**
 * CS1010 AY2017/8 Semester 1 Lab6 Ex3
 * elevator.c
 * This program helps Brusco to simulate the running of elevators
 * Jeevan Neralakere Somashekhar
 * C04
 */

#include <stdio.h>
#include <string.h>
#define CAPACITY 15
#define MAX_LEN 21
#define MAX_ELEVATORS 5

// define a structure called elevator_t
typedef struct { 
	int floor,passenger,usage;
} elevator_t;

void setupElevators(elevator_t [], int);
void readSequences(char [][MAX_LEN], int);
void runElevators(elevator_t [], char [][MAX_LEN], int);
void goToFloor(elevator_t *, int);
void printElevators(elevator_t [], int size);
int mostUsedElevator(elevator_t [], int);

// This function is given. You are NOT to modify it.
int main(void){
	int size;
	elevator_t elevators[MAX_ELEVATORS] = {{0}};
	char sequences[MAX_ELEVATORS][MAX_LEN] = {{'\0'}};
	
	printf("Enter number of elevators: ");
	scanf("%d", &size);
	
	setupElevators(elevators, size);
	readSequences(sequences, size);
	
	runElevators(elevators, sequences, size);
	
	printElevators(elevators, size);
	printf("Most used elevator: %d\n", mostUsedElevator(elevators, size));
	
	return 0;
}
// Pre Cond: Size > 0
// Initialize each elevator's floor to be 1, and its number of passengers and usage to be 0
void setupElevators(elevator_t elevators[], int size){
	int i = 0;

	for (i = 0;i < size;i++) {
		elevators[i].floor = 1;
		elevators[i].passenger = 0;
		elevators[i].usage = 0;
	}
}
// Read in the sequences of floors the elevators go to.
// This function is given. You are NOT to modify it.
void readSequences(char sequences[][MAX_LEN], int size){
	int i = 0,j = 0,len;
	
	for (i = 0; i<size; i++){
		printf("Enter sequence for elevator %d: ", i+1);
		scanf("%s", sequences[i]);
	}
}
// Pre Cond: Size > 0
// This function runs the elevators 
void runElevators(elevator_t elevators[], char sequences[][MAX_LEN], int size){
	int floor, i = 0, j = 0,len;
	// Each elevator has its own sequence 
	// For each sequence, an action will happen
	for (i = 0;i < size;i++) {
		len = strlen(sequences[i]);
		for (j = 0;j < len;j++) {
			// Since the sequence is of char type, we have to -48 from its ASCII  value
			floor = sequences[i][j] - 48;
			if (j == 0) {
				elevators[i].floor = floor;
				elevators[i].passenger = floor;
			}
			else {
				// Passes the pointer and current floor value to another function 
				goToFloor(&elevators[i],floor);
			}
		}
	}
}
// This function updates the current floor,passenger and usage values for the particular elevator 
void goToFloor(elevator_t *elevator, int floor){
	
	// when elevator is going up
	if (floor > (*elevator).floor) {
		if (floor + (*elevator).passenger > 15) {
			// Sets limit of passengers to 15
			(*elevator).floor = floor;
			(*elevator).passenger = 15;
		}
		else {
			(*elevator).passenger += floor;
			(*elevator).floor = floor;
		}
	}
	// when elevator is going down 
	else if ((*elevator).floor > floor) {
		if ((*elevator).passenger < floor) {
			// since number of passengers is smaller than floor number
			// all the passengers will leave, and this number will be added to usage 
			(*elevator).usage += (*elevator).passenger;
			(*elevator).passenger -= (*elevator).passenger;
			(*elevator).floor = floor;
		}
		else if (floor < (*elevator).passenger) {
			// since floor number is smaller than number of passengers
			// the number of passengers will minus away the floor number 
			// the floor number wil get added to the usage
			(*elevator).passenger -= floor;
			(*elevator).floor = floor;
			(*elevator).usage += floor;
		}
	}
}
// Prints the end values for the respective elevators
// Pre Cond: Size > 0
void printElevators(elevator_t elevators[], int size){
	int i = 0;

	for (i = 0;i< size;i++) {

		printf("Elevator %d:\n",i+1); 
		printf("Floor: %d\n",elevators[i].floor);
		printf("Number of passengers: %d\n",elevators[i].passenger);
		printf("Usage: %d\n",elevators[i].usage);
	}
}
// Pre Cond: Find the elevator which has the most usage 
int mostUsedElevator(elevator_t elevators[], int size){
	int i = 0,elevator_type,max = 0,num_passengers = 0;
	
	for (i = 0;i < size;i++) {
		if (elevators[i].usage > max) {
			max = elevators[i].usage;
			num_passengers = elevators[i].passenger;
			elevator_type = i + 1;
		}
		else if ((elevators[i].usage == max) && (elevators[i].passenger > num_passengers)) {
			max = elevators[i].usage;
			num_passengers = elevators[i].passenger;
			elevator_type = i + 1;
		}
		
	}
	return elevator_type;
}

