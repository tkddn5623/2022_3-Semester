#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
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
int main() {
	int A, B, N, K; //B = A + interval
	int* primes = getPrimes(2237, NULL);
	long long int min = LLONG_MAX;
	scanf("%d%d", &A, &B);
	if (A > B) {
		int temp = A;
		A = B;
		B = A;
	}
	const int A_1 = A + 1, B_1 = B + 1;
	const int interval = B - A;
	for (int i = 1; min > (B + (long long int)i); i++) {
		if (min > lcm(A + i, B + i)) {
			min = lcm(A + i, B + i); // Make this part fast
			N = i;
		}
		printf("A[%4d] B[%4d] lcm[%12lld]\n", A + i, B + i, lcm(A + i, B + i));
	}
	/*int answer = INT_MAX;
	for (int i = 1;; i++) {
		if (answer <= i * B_1) break;
		int denom, denomLimit, index = 0, icopy = interval * i;
		int factorVal[100] = { 0 };
		int factorCof[100] = { 0 };
		denomLimit = interval / A_1;
		
		for (int j = 0;; j++) {
			if ((primes[j] * primes[j]) > icopy) {
				if (icopy != 1) {
					//printf("%d ", icopy);
					factorVal[index] = icopy;
					factorCof[index++]++;
				}
				break;
			}
			if (!(icopy % primes[j])) {
				while (!(icopy % primes[j])) {
					//printf("%d ", primes[j]);
					factorVal[index] = primes[j];
					factorCof[index]++;
					icopy /= primes[j];
				}
				index++;
			}
		}
		denom = 1;
		int value = 1;
		int count[100] = { 1 }; // 1, 0 , 0 ...
		while (value < interval) {
			value = 1;
			for (int j = 0; j < index; j++) {
				for (int k = 0; k < count[j]; k++) {
					value *= factorVal[j];
				}
			}
			//printf("Now V is [%d]\n", value);
			if (denom < value && value <= denomLimit && (value % i != 0 || i == 1)) denom = value;
			for (int j = 0; j < index; j++) {
				count[j]++;
				if (count[j] <= factorCof[j]) break;
				else {
					count[j] = 0;
				}
			}

		}
		if (denom == 1) printf("Fail. i %d\n", i);
		else {
			answer = (denom + i) * interval / denom;
			printf("a is %d\n", answer);
		}
	}
	//printf("Denom is %d\n", denom);
	printf("My answer is %d\n", answer);*/

	printf("min v [%lld], B/A is [%d/%d]\n", min, ((B + N) / gcd(A + N, B + N)), (A + N) / gcd(A + N, B + N));
	printf("B' is [%d]\n", B + N);
	printf("%d\n", N);
}
