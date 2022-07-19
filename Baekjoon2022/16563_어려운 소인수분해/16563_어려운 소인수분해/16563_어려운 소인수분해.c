#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int* getPrimes(int n, int* psize) {
	int count = 0;
	bool* isPrime = malloc((n + 2) * sizeof(bool));
	if (isPrime == NULL) {
		printf("error occured!\n");
		exit(1);
	}
	memset(isPrime, 1, (n + 2) * sizeof(bool));
	isPrime[0] = false, isPrime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (int j = 2; (i * j) <= n; j++) {
				isPrime[i * j] = false;
			}
			count++;
		}
	}
	int* primes = malloc(count * sizeof(int));
	int index = 0;
	if (primes == NULL) {
		printf("error occured!\n");
		exit(1);
	}
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) primes[index++] = i;
	}
	free(isPrime);
	if(psize != NULL) *psize = count;
	return primes;
}

int main(){
	int N, number;
	//int primeSize;
	//int* primes = getPrimes(2237, &primeSize);
	int* primes = getPrimes(2237, NULL);
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &number);
		//for (int j = 0; j < primeSize; j++)
		for (int j = 0;; j++) {
			if ((primes[j] * primes[j]) > number) {
				if (number != 1) printf("%d ", number);
				break;
			}
			while (!(number % primes[j])) {
				printf("%d ", primes[j]);
				number /= primes[j];
			}
		}
		printf("\n");
	}
}