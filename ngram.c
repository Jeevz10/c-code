// CS1010 AY2014/5 Semester 1
// PE2 Ex1: ngram.c
// Name: 
// Matriculation number: 
// plab-id: 
// Discussion group: 
// Description: 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 101
int mostFrequentUnigram(char [],char []);
int mostFrequentBigram(char [],char []);

int main(void) {
	char text[MAX_SIZE], result[3] ={'\0'};
	int len,option, unigramFreq, bigramFreq;

	printf("Enter text: ");
	fgets(text,MAX_SIZE + 1,stdin);
	
	len = strlen(text);

	if (text[len - 1] == '\n') {
		text[len - 1] = '\0';
	}

	printf("Enter option: ");
	scanf("%d",&option);
	
	if (option == 1) {

		unigramFreq = mostFrequentUnigram(text,result);
		printf("Most frequent unigram: %s\n", result);
		printf("Frequency: %d\n", unigramFreq);
	}
	else {

		bigramFreq = mostFrequentBigram(text,result);
		printf("Most frequent bigram: %s\n", result);
		printf("Frequency: %d\n", bigramFreq);
	}
	
	return 0;
}

int mostFrequentUnigram(char text[],char result[]) {
	int i = 0,j = 0,len,sum = 0,count = 1;
	char ch,tempresult[1] = {'\0'};

	len = strlen(text);

	for (i = 0;i < len;i++) {
		count = 1;
		ch = text[i];
		tempresult[0] = ch;
		if (ch == ' ') {
			continue;
		}
		for (j = i + 1;j < len;j++) {
			if (text[j] == ch) {
				count++;
			}
		}
		if (count > sum) {
			sum = count;
		//	strcpy(result,tempresult);
			result[0] = tempresult[0];
		}
		else if ((count == sum) && (tempresult[0] < result[0])) {
		//	strcpy(result,tempresult);
			result[0] = tempresult[0];
		}
	}
	return sum;
}

int mostFrequentBigram(char text[],char result[]) {
	int i = 0,j = 0,count = 0,sum = 0,len;
	char ch[2] = {'\0'};

	len = strlen(text);

	for (i = 0;i < len;i++) {
		count = 1;
		ch[0] = text[i];
		ch[1] = text[i + 1];
		if ((ch[0] == ' ') || (ch[1] == ' ')) {
			continue;
		}
		if (i == len - 1) {
			break;
		}
		for (j = i + 2;j < len;j++) {
			if ((text[j] == ch[0]) && (text[j + 1] == ch[1])) {
				count++;
			}
			if (j == len - 2) {
				break;
			}
		}
		if (count > sum) {
			sum = count;
		//	strcpy(result,ch);
			result[0] = ch[0];
			result[1] = ch[1];
		}
		else if ((count == sum) && (ch[0] < result[0])) {
			strcpy(result,ch);
			result[0] = ch[0];
			result[1] = ch[1];
		}
	}
	result[2] = '\0';
	return sum;
}


