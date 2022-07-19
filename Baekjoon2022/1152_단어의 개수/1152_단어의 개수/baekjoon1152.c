#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
#define MAX 1000000

int numWords(const char* str) {
	int count = 0;
	char* word;

	word = strtok(str, " ");
	while (word != NULL) {
		if (strcmp(word, "\n")) count++;
		//printf("[%s]\n", word);
		word = strtok(NULL, " ");
	}
	return count;
}

char str[MAX];
int main()
{
	//char str[MAX] = malloc(MAX);
	fgets(str, MAX, stdin);
	printf("%d\n", numWords(str));
}