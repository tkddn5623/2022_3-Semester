#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1048576 //2^20
#define BITS (sizeof(int) * 8)

int bitChange(int a, int n)
{
	return a | (1 << n); //0~31
}
int bitCheck(int a, int n)
{
	return (a & (1 << n)) >> n ? 1 : 0;
}
int main()
{
	int num;
	int* set = calloc(MAX, sizeof(int));
	do {
		scanf("%d", &num);
		if (!bitCheck(set[num / BITS], num % BITS)) 
			printf("%d ", num);
		set[num / BITS] = bitChange(set[num / BITS], num % BITS);
	} while (getchar() != '\n');
	free(set);
}