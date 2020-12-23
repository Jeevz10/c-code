#include <string.h>
#include <ctype.h>
#include <stdio.h>

void translate(char [],char []);

int main(void) {
	char sentence[20],output[20];

	printf("Enter sentence: ");
	fgets(sentence,51,stdin);

	translate(sentence,output);

	printf("%s\n",output);

	return 0;
}

void translate(char sentence[],char output[]) {
	int i = 0,count = 0,len;
	char *token;

	token = strtok(sentence," ");

	while (token != NULL) {

		len = strlen(token);
		
		for (i = 0;i < len;i++) {
			if (token[i] == 'a') {
				token[i] = 'o';
				break;
			}
		}

		strcat(output,token);

		++count;

		if (count % 2 == 1) {
			strcat(output," wa");
		}

		else if(count % 2 == 0) {
			strcat(output, " fa");
		}

		token = strtok(NULL," ");

		if (token != NULL) {
			strcat(output," ");
		}

		else {
			break;
		}
	}

	len = strlen(output);

	output[len] = '\0';

}
