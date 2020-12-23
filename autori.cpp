#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main() {

	char string[100] = "\0";
	char *token;
	char store[100] = "\0";

	fgets(string,101,stdin);

	token = strtok(string,"-");

	while (token != NULL) {
		strcat(store,token[0]);
	}

	printf("%s",store);

	return 0;
}
