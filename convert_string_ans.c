// convert_string_ans.c 
#include <stdio.h>
#include <string.h>
#define MAX_LEN 20

void convert_string(char [], char []);

int main(void) {
	char str1[MAX_LEN+1], str2[2*MAX_LEN+1];
	int len;

	printf("Enter string (at most %d char): ", MAX_LEN);
	fgets(str1, MAX_LEN+1, stdin);
	len = strlen(str1);
	if (str1[len - 1] == '\n');
		str1[len - 1] = '\0';

	convert_string(str1, str2);
	printf("Converted: %s\n", str2);
	return 0;
}

// Add an asterisk between each letter in src.
void convert_string(char src[], char dest[]) {
	int i=0, j=0;

	while (src[i] != '\0') {
		if (src[i] == ' ')
			i++;
			dest[j++] = src[i++];
			dest[j++] = '*';
	}
	dest[j-1] = '\0';
}

