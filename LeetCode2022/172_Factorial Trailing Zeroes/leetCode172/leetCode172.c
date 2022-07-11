#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fact(int n)
{
	int num = 1;
	for (int i = 2; i <= n; i++) {
		num *= i;
	}
	return num;
}
int trailingZeroes(int n) {
	int temp;
	int count2 = 0, count5 = 0;
	for (int i = 2; i <= n; i++) {
		temp = i;
		while (temp % 2 == 0) {
			count2++;
			temp /= 2;
		}
		temp = i;
		while (temp % 5 == 0) {
			count5++;
			temp /= 5;
		}
	}
	return count2 < count5 ? count2 : count5;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", trailingZeroes(n));
	printf("%d\n", fact(n));
}