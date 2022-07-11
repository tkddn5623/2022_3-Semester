#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int climbStairs(int n) {
	static int memory[50] = { 0, 1, 2 };
	if (memory[n] != 0 || n == 0) 
		return memory[n];
	else {
		memory[n] = climbStairs(n - 1) + climbStairs(n - 2);
		return memory[n];
	}
}

int main()
{
	int num;
	scanf("%d", &num);
	printf("%d\n", climbStairs(num));
}