// anagrams.c
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#define MAX_LENGTH 60

void sortAlpha(char []);
int areAnagrams(char [], char []);

int main(void) {
	char phrase1[MAX_LENGTH+1], phrase2[MAX_LENGTH+1];
	int len;

	printf("Enter 1st phrase: ");
	fgets(phrase1,MAX_LENGTH +1,stdin);
	
	len = strlen(phrase1);
	if (phrase1[len - 1] == '\n') {
		phrase1[len - 1] = '\0';
	}
//	getchar();

	printf("%s\n", phrase1); // print the input

	printf("Enter 2nd phrase: ");
	fgets(phrase2,MAX_LENGTH + 1,stdin);
	
	len = strlen(phrase2);
	if (phrase2[len - 1] == '\n') {
		phrase2[len - 1] = '\0';
	}
//	getchar();

	printf("%s\n", phrase2); // print the input
	
	sortAlpha(phrase1);
	sortAlpha(phrase2);

	if (areAnagrams(phrase1, phrase2))
		printf("They are anagrams.\n");
	else
		printf("They are not anagrams.\n");

	return 0;
}

void sortAlpha(char str[]) {
	int i,j,min_index,temp,start,size;
	
	size = strlen(str);

	for (i = 0;i < size;i++) {
		if (!isalpha(str[i])) {
			for (j = i;str[j] != '\0';j++) {
				str[j] = str[j+1];
			}
			str[j] = '\0';
			--size;
		}
	}

//	printf("%s\n",str);

	for (start = 0;start < size - 1;start++) {
		min_index = start;

		for (i = start + 1;i < size;i++) {
			if (tolower(str[i]) < tolower(str[min_index])) {
				min_index = i;
			}
		}

		temp = str[start];
		str[start] = str[min_index];
		str[min_index] = temp;
	}

//	printf("%s\n",str);
}

// Return 1 if str1 and str2 are anagrams,
// otherwise return 0.
int areAnagrams(char str1[], char str2[]) {
	int i,len;

	len = strlen(str1);

	for (i = 0;i < len;i++) {
		if (tolower(str1[i]) != tolower(str2[i])) {
			return 0;
		}
	}
	return 1;
}

