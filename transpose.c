// transpose.c

#include <stdio.h>
#define MAX_ROWS 10      // maximum number of rows
#define MAX_COLS 10     // maximum number of columns 
#define MAX_LENGTH 100   // maximum number of characters in the message & result

int encrypt(int, int, char [], char []);
int decrypt(int, int, char [], char []);

int main(void) {
	int rows,cols,choice,len,isgood;
	char message[MAX_LENGTH],result[MAX_LENGTH];

	printf("Enter 1 for encryption, 2 for decryption: ");
	scanf("%d",&choice);

	printf("Enter dimensions of a 2D array: ");
	scanf("%d %d",&rows,&cols);
	getchar();

	printf("Enter message: ");
	fgets(message,MAX_LENGTH+1,stdin);
	
	if (choice == 1) {
		isgood = encrypt(rows,cols,message,result);
		
		if (isgood == 1) {
			printf("Encrypted message: %s\n", result);
		}
		else {
			printf("Encryption failed.\n");
		}
	}
	else if (choice == 0) {
		isgood = decrypt(rows,cols,message,result);
		
		if (isgood == 1) {
			printf("Decrypted message: %s\n", result);
		}
		else {
			printf("Decryption failed.\n");
		}
	}
	
	return 0;
}

// Encrypt a message based on transposition algorithm
int encrypt(int rows, int cols, char message[], char result[]){
	int r = 0,c = 0,len,i = 0,j = 0;
	char temp[rows][cols],ch;

	len = strlen(message);
	if ((rows * cols) < len) {
		return 0;
	}

	for (i = 0;i < rows;i++) {
		for (j = 0;j < cols;j++) {
			ch = message[i*cols + j];
			if (!isalnum(ch)) {
				ch = '@';
			}
			temp[i][j] = ch;
		}
	}
	for (i = 0;i < cols;i++) {
		for (j = 0;j < rows;j++) {
			result[i * rows + j] = temp[j][i];
		}
	}
	return 1;
}

// Decrypt a message based on transposition algorithm
int decrypt(int rows, int cols, char message[], char result[]){
	int i = 0,j = 0;
	char ch,temp[rows][cols];

	for (i = 0;i < cols;i++) {
		for (j = 0;j < rows;j++) {
			ch = message[i * rows + j];
			temp[j][i] = ch;
		}
	}
	for (i = 0;i < rows;i++) {
		for (j = 0;j < cols;j++) {
			if (temp[i][j] == '@') {
				result[i * cols + j] = '\0';
				return 1;
			}
			else {
				result[i * cols + j] = temp[i][j];
			}
		}
	}
	return 1;
}
