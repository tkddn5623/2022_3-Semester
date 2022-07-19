#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//int array_t[10000000] = {0};
int countPrimes(int n) {
	int count = 0;
	bool* isPrime = malloc((n + 2) * sizeof(bool)); // index from 0 to n + 1
	if (isPrime == NULL) {
		printf("error occured!\n");
		exit(1);
	}
	memset(isPrime, 1, (n + 2) * sizeof(bool));
	isPrime[0] = false, isPrime[1] = false;
	for (int i = 2; i < n; i++) { //false(0) will mean 'That is not prime'
		if (isPrime[i]) {         //if i <= n, it will include 'n' is prime or not.
			for (int j = 2; (i * j) <= n; j++) {
				isPrime[i * j] = false;
			}
			count++;
		}
	}
	free(isPrime);
	return count;
}

int main()
{
	printf("%d\n", countPrimes(3));
}
