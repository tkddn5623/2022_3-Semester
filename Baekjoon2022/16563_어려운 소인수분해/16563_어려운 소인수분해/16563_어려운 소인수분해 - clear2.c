#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* getFactorList(const int maxprime) {
	int length = 0;
	int* factorList = calloc(maxprime + 2, sizeof(int));
	int* primeList = calloc(maxprime, sizeof(int));

	if (factorList == NULL || primeList == NULL) exit(1);
	factorList[0] = -1, factorList[1] = -1;
	for (int i = 2; i <= maxprime; i++) {
		if (!factorList[i]) primeList[length++] = i;
		for (int j = 0; j < length; j++) {
			if (i * primeList[j] > maxprime) break;
			factorList[i * primeList[j]] = primeList[j];
			if (i % primeList[j] == 0) break;
		}
	}
	free(primeList);
	return factorList;
}

int main(){
	int N, number;
	int* primes = getFactorList(5000000);
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &number);
		while (1) {
			if (primes[number] == 0) {
				printf("%d\n", number);
				break;
			}
			else {
				printf("%d ", primes[number]);
				number /= primes[number];
			}
		}
	}
}