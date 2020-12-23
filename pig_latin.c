// pig_latin.c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LENGTH 80 

void convert(char [],int,char []);

int main(void) {
	char str[LENGTH],conv[LENGTH] = {'\0'};
	int len;

	printf("Enter sentence: ");
	fgets(str,LENGTH + 1,stdin);

	len = strlen(str);

	if (str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
	len = strlen(str);
	convert(str,len,conv);

	printf("\nConverted: %s\n", conv);

	return 0;
}

// Convert src into pig-latin in dest
void convert(char str[],int len, char conv[]) {
	int i = 0,j,isVowel = 0;
	char way[5] = "way ",ay[4] = "ay ";

	for (i = 0;i < len;i++) {
		isVowel = 0;

		if ((tolower(str[i]) == 'a') || (tolower(str[i]) == 'e') || (tolower(str[i]) == 'i') || (tolower(str[i]) == 'o') || (tolower(str[i]) == 'u')) {
			isVowel = 1;
		}
		j = i;

		while (!isspace(str[j])) {
			j++;
		}

		if (isVowel == 1) {
			strncat(conv,&str[i],j - i);
			strncat(conv,way,4);
		}
		else {
			strncat(conv,&str[i + 1],j - i -1);
			strncat(conv,&str[i],1);
			strncat(conv,ay,3);
		}
		i = j;
	}
}
