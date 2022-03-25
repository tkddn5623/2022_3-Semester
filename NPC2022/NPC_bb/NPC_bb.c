#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int power(int a, int b)
{
	int c = 1;
	for (int i = 0; i < b; i++)
		c = c * a;
	return c;
}
int sum(int* slot)
{
	int s = 0;
	for (int i = 0; i < 7; i++) {
		s = s + slot[i] * power(7, i);
	}
	return s;
}
int main()
{
	int input;
	int level = 1;
	int slot[8] = { 0 };
	slot[0] = 1;
	scanf("%d", &input);
	while (1) {
		//printf("S is %d\n", sum(slot));
		if (sum(slot) == input) {
			//printf("Now level is %d\n", level);
			break;
		}
		else {
			slot[0]++, level++;
		}
		for (int i = 0; i < 7; i++) {
			if (slot[i] >= 3) {
				slot[i + 1]++;
				slot[i] = slot[i] - 3;
			}
		}
		if (slot[7] == 1) {
			printf("Fail\n");
			return -1;
		}
	}
	printf("%d", level);
}