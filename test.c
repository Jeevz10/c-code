#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char str[51] = "all me",str1[5]= {" all"},len,*ptr;
	char test[2];

	printf("Enter test: ");
	scanf("%s",test);
	
	len = strlen(test);

	printf("%d %s\n",len,test);

	if (test[len - 1] == '\n') {
		test[len - 1] = '\0';
	}
	printf("Its length is %d and test is:%s\n)",strlen(test),test);

	/*
	
	strcpy(str,str1);
	printf("%s\n",str);
	while (ptr != NULL) {
		printf("%s",ptr);
		ptr = strtok(str,str1);
	}
*/


/*	
	if (ptr == NULL) {
		printf("0\n");
	}
	else {
		while (ptr != NULL) {
		printf("str1 is %c while str is %s after this\n",str1,ptr);
		ptr = strtok(NULL,str1);
		}
	}
*/
	return 0;
}
/*
	printf("Enter a string:");
	fgets(str,51,stdin);

	len = strlen(str);
	
	printf("%d\n",len);

	if (str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
	
	len = strlen(str);

	printf("%d\n",len);

//	strncpy(str1,str,50);

	printf("%s",str1);

	return 0;
}*/
