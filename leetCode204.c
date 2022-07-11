/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int countPrimes(int n) {
	int* array_t = malloc(sizeof(int) * (n + 1)); // index from 0 to n
	printf("%d", )
	free(array_t);
	return &array_t[5];
}

int main()
{
	printf("%d", *p);
}*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int* p = calloc(5, sizeof(int));
	int* pt[5];
	int i;
	printf("address of p  is %p\n", p);
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;
	p[3] = 4;
	p[4] =  5;
	
	pt[0] = realloc(p, 4 * sizeof(int));
	pt[1] = realloc(pt[0], 3 * sizeof(int));
	printf("v is %d\n", *(pt[0] + 4));
}