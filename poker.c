// CS1010 AY2012/3 Semester 1
// PE2 Ex2: poker.c
// Name: 
// Matriculation number: 
// plab account-id: 
// Discussion group: 
// Description:

#include <stdio.h>
#define NUMBER_OF_CARDS 5

void read_hand(int []);
void type_and_keycard_ranks(int [],int *,int *);
int who_wins(int,int,int,int);

int main(void) {
	int hand1[NUMBER_OF_CARDS], hand2[NUMBER_OF_CARDS],type1,kc1,type2,kc2;
	int winner;

	// Read in the hand of the first player
	printf("Enter the hand of player 1:\n");
	read_hand(hand1);

	type_and_keycard_ranks(hand1,&type1,&kc1);
	
	// Read in the hand of the second player
	printf("Enter the hand of player 2:\n");
	read_hand(hand2);

	type_and_keycard_ranks(hand2,&type2,&kc2);

	winner = who_wins(type1,kc1,type2,kc2);
	
	printf("Player 1 has a hand of type rank %d and key card rank %d.\n",type1,kc1);
	printf("Player 2 has a hand of type rank %d and key card rank %d.\n",type2,kc2);

	if (winner == 1) {
		printf("Player 1 wins.\n");
	}
	else if (winner == 2) {
		printf("Player 2 wins.\n");
	}
	else if (winner == 3) {
		printf("There is a draw.\n");
	}

	return 0;
}

// Reads an array of integers representing a hand
void read_hand(int hand[]) {
	int i;
	
	for (i = 0; i < NUMBER_OF_CARDS; i++) {
		scanf("%d", &hand[i]);
	}
}

void type_and_keycard_ranks(int arr[],int *type,int *kc) {
	int i = 0,j,temptype = 1,tempcard = 0,t = 0,card = 0;

	for (i = 0;i < NUMBER_OF_CARDS;i++) {
		for (j = i + 1;j < NUMBER_OF_CARDS;j++) {
			tempcard = arr[i];
			if (arr[j] == arr[i]) {
				temptype++;
			}
			if (j == NUMBER_OF_CARDS - 1) {
				break;
			}
		}
		if (temptype > t) {
			t = temptype;
			card = tempcard;
		}
		else if (((temptype == t) && (tempcard > card)) || ((temptype == t) && (tempcard == 1)))  {
			card = tempcard;
		}
		temptype = 1;
		tempcard = 0;
	}
	*type = t;
	if (card == 1) {
		*kc = 13;
	}
	else {
		*kc = card - 1;
	}
}

int who_wins(int type1,int kc1,int type2,int kc2) {
	int winner;

	if (type1 > type2) {
		winner = 1;
	}
	else if (type2 > type1) {
		winner = 2;;
	}
	else if (type1 == type2) {
		if (kc1 > kc2) {
			winner = 1;;
		}
		else if (kc2 > kc1) {
			winner = 2;;
		}
		else if (kc1 == kc2) {
			winner = 3;
		}
	}
	return winner;
}
