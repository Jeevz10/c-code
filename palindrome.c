// palindrome.c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 20

int isPalindrome(char [],int);

int main(void) {
	char word[MAXLEN+1];
	int len,len1;

	printf("Enter word: ");

	fgets(word,MAXLEN + 1,stdin);
	len = strlen(word);
//	printf("%d",len);

	if (word[len-1] == '\n') {
		word[len-1] = '\0';
	}
	len1 = strlen(word);
//	printf("%d",len1);

	if (isPalindrome(word,len1))
		printf("\"%s\" is a palindrome.\n",word);
	else
		printf("\"%s\" is not a palindrome.\n",word);

	return 0;
}

// Return 1 if str is a palindrome, otherwise return 0.
int isPalindrome(char str[],int len1) {
	int i = 0,k = len1 - 1;
	
	for (i = 0;i < len1;i++) {
		if (tolower(str[i]) != tolower(str[k])) {
			return 0;
		}
		k--;
	}
	return 1;
}
