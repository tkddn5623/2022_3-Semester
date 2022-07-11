#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//int array_t[10000000] = {0};
int countPrimes(int n) {
	int count = 0;
	bool* array_t = calloc(n + 2, sizeof(bool)); // index from 0 to n + 1
	array_t[0] = true, array_t[1] = true;
	for (int i = 2; i < n; i++) { //true(1) will mean That is not prime.
		if (array_t[i] == false) {
			//printf("Counting! [%d]\n", i);
			for (int j = 2; (i * j) <= n; j++) {
				array_t[i * j] = true;
			}
			count++;
		}
	}
	free(array_t);
	return count;
}

int main()
{
	printf("%d\n", countPrimes(2));
}
