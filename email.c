// CS1010 AY2015/6 Semester 1
// PE2 Ex2: email.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 51

int checkEmail(char email[]);
int main(void){
	int result;
	char email[MAX_LENGTH];
	
	printf("Enter email address: ");
	scanf("%s", email);
	
	result = checkEmail(email);

	if (result == 0) {
		printf("This email address is not valid.\n");
	}
	else if (result == 1) {
		printf("This email address is valid but not friendly.\n");
	}
	else if (result == 2) {
		printf("This email address is valid and friendly.\n");
	}
	return 0;
}

int checkEmail(char email[]) {
	int i = 0,j = 0,len;
	char at[1] = "@",dom[10] = "u.nus.edu",result;
	char local[MAX_LENGTH] = {'\0'},domain[MAX_LENGTH] = {'\0'};
	
	len = strlen(email);

	for (i = 0;i < len;i++) {
		if (email[i] == '@') {
			break;
		}
		if (i == len - 1) {
			return 0;
		}
	}

	strcpy(local,strtok(email,at));
	strcpy(domain,strtok(NULL,at));

	len = strlen(local);

//	printf("%s\n",local);
//	printf("%s\n",domain);
//	printf("%d\n",len);

	if ((len < 3) || (len > 21)) {
		return 0;
	}

	if (!isalpha(local[0])) {
		return 0;
	}
	for (i = 0;i < len;i++) {
		if ((isalpha(local[i])) || (isdigit(local[i])) || (local[i] == '.')) {
	//		printf("%c\n",local[i]);
			continue;
		}
		else {
			return 0;
		}
	}
	if (strcmp(dom,domain) != 0) {
//		printf("%s",dom);
//		printf("%s",domain);
		return 0;
	}

	if (((local[0] == 'a') || (local[0] == 'e')) && (len == 8)) {
		for (j = 1;j < 8;j++) {
			if (!isdigit(local[j])) {
				return 2;
			}
		}
	}
	else {
		return 2;
	}
	return 1;
}

