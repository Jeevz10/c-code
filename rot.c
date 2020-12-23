// rot.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 80

void encrypt(char [], char []);
void decrypt(char [], char []);

int main(void) {
	char message[MAX_LENGTH],result[MAX_LENGTH],len;
	int choice;

	printf("Enter 1 for encryption, 2 for decryption: ");
	scanf("%d",&choice);
	printf("Enter message: ");
//	fgets(message,MAX_LENGTH + 1,stdin);

	scanf("%s",message);
	len = strlen(message);
/*
	if (message[len - 1] == '\n') {
		message[len - 1] = '\0';
	}
*/	
	if (choice == 1) {
		encrypt(message,result);
		printf("Encrypted message: %s\n",result);
	}
	else if (choice == 2) {
		decrypt(message,result);
		printf("Decrypted message: %s\n",result);
	}

	return 0;
}

// Encrypt a message based on transpose-13 algorithm
void encrypt(char message[], char result[]){
	int len,i = 0;

	len = strlen(message);

	for (i = 0;i < len;i++) {
		if (islower(message[i])) {
			if (message[i] < 'n') {
				result[i] = message[i] + 13;
			}
			else if (message[i] > 'm') {
				result[i] = message[i] - 13;
			}
		}
		else if (isupper(message[i])) {
			if (message[i] < 'N') {
				result[i] = message[i] + 13;
			}
			else if (message[i] > 'M') {
				result[i] = message[i] - 13;
			}
		}
	}
	len = strlen(result);

	if (result[len - 1] == '\n') {
		result[len - 1] = '\0';
	}
}

// Decrypt a message based on transpose-13 algorithm
void decrypt(char message[], char result[]){
	int len,i = 0;

	len = strlen(message);

	for (i = 0;i < len;i++) {
		if (islower(message[i])) {
			if (message[i] < 'n') {
				result[i] = message[i] + 13;
			}
			else if (message[i] > 'm') {
				result[i] = message[i] - 13;
			}
		}
		else if (isupper(message[i])) {
			if (message[i] < 'N') {
				result[i] = message[i] + 13;
			}
			else if (message[i] > 'M') {
				result[i] = message[i] - 13;
			}
		}
	}
	len = strlen(result);

	if (result[len - 1] == '\n') {
		result[len - 1] = '\0';
	}
}
