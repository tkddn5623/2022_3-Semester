#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	while (1) {
		srand((unsigned int)time(NULL));
		rand();
		int N = (rand() % 1199) + 2;
		int K = (rand() % 99999) + 2;
		int T = (rand() % 1000000001);
		int A;
		int mod = 0;
		printf("%d %d %d\n", N, K, T);
		for (int i = 0; i < N; i++) {
			A = rand() % K;
			if (i < N - 1) {
				printf("%d ", A);
				mod += A % K;
			}
			if (mod >= K) {
				mod = mod % K;
			}
		}
		printf("%d\n", K - mod);
		system("pause");
		system("cls");
	}
}