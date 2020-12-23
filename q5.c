// q5.c
#include <stdio.h>
#include <string.h>
 
int main(void) {
	char *fruit1 = "apple", *fruit2 = "apple";
	char *str1 = "yes", *str2 = "yes";
	
	fruit1 = str1;
	printf("%s\n", fruit1);

	fruit1 = "nooo";
	printf("%s\n",fruit1);
/*
	strcpy(fruit2, str2);
	printf("%s\n", fruit2);
*/
	return 0;
}

