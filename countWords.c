// countWords.c
#include <stdio.h>
#include <ctype.h>
#define LENGTH 50

int word_count(char []);

int main(void) {
	int i = 0,len = 0;
	char sentence[LENGTH];

	printf("Enter a sentence with at most %d characters:\n", LENGTH);

	fgets(sentence,LENGTH,stdin);
/*
	for (i = 0;i < LENGTH;i++) {
		if (isalphanum(sentence[i])) {
			len++;
		}
	}
	if (sentence[len - 1] == '\n') {
		sentence[len - 1] == '\0';
		} */
	printf("Sentence = %s\n", sentence); 
	
	printf("Word count = %d\n", word_count(sentence));

	return 0;
}

// Count the number of words in str
int word_count(char str[]) {
	int j = 0,i = 0,words = 0,firstpos = 0;

	for (i = 0;i < LENGTH;i++) {
		if (isspace(str[i])) {
			for (j = firstpos;j < i;j++) {
				if (isalpha(str[j])) {
					words++;
					break;
				}
			}
			firstpos = i + 1;
		}
		if (str[i] == '\n') {
			break;
		}
	}
		return words;
}
