#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#define lcm(a, b) ((long long int)(a) / gcd(a, b) * (b))
int gcd(int a, int b) { // gcd function implemented as Iteration
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
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
	if (psize != NULL) *psize = count;
	return primes;
}
int miniLCM(int A, int B) {
	if (A == B) return 1;
	else if (A > B) {
		int temp = A;
		A = B;
		B = temp;
	}
	long long int minLCM = LLONG_MAX;
	const int interval = B - A;
	int primeSize;
	int* primes = getPrimes(29999, &primeSize);
	int* factorVal = malloc(primeSize * sizeof(int));
	int* factorCof = malloc(primeSize * sizeof(int));
	int* count = malloc(primeSize * sizeof(int));
	for (int i = 1;; i++) {
		if (minLCM <= i * (long long int)(B + 1)) break;
		int index, icopy, denom, denomLimit, multiple;
		index = 0;
		icopy = interval * i;
		denom = 1;
		denomLimit = icopy / (A + 1);
		if (denomLimit == 0) {
			i = A / interval;
			continue;
		}
		memset(factorVal, 0, primeSize * sizeof(int));
		memset(factorCof, 0, primeSize * sizeof(int));
		memset(count, 0, primeSize * sizeof(int));
		count[0] = 1;
		for (int j = 0;; j++) {
			if ((primes[j] * primes[j]) > icopy) {
				if (icopy != 1) {
					factorVal[index] = icopy;
					factorCof[index++]++;
				}
				break;
			}
			if (!(icopy % primes[j])) {
				while (!(icopy % primes[j])) {
					factorVal[index] = primes[j];
					factorCof[index]++;
					icopy /= primes[j];
				}
				index++;
			}
		}
		do {
			multiple = 1;
			for (int j = 0; j < index; j++) {
				for (int k = 0; k < count[j]; k++)
					multiple *= factorVal[j];
			}
			if (denom < multiple && multiple <= denomLimit && (multiple % i != 0 || i == 1)) denom = multiple;
			for (int j = 0; j < index; j++) {
				count[j]++;
				if (count[j] <= factorCof[j]) break;
				else {
					count[j] = 0;
				}
			}
		} while (multiple < interval);
		if (denom <= denomLimit) {
			long long int temp = (long long int)(denom + i) * interval / denom;
			if (minLCM > temp) minLCM = temp;
		}
	}
	free(count);
	free(primes);
	free(factorVal);
	free(factorCof);
	return minLCM - B;
}
int main() {
	int A, B;
	scanf("%d%d", &A, &B);
	printf("%d\n", miniLCM(A, B));
}
