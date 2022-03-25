#include <stdio.h>

int main()
{
	int a1 = -2147483647;
	unsigned a2 = 1U;
	int a3 = 2147483647;
	//printf("%u, %u\n", a1 - a2, a3);
	

	int tx1 = -15;
	int tx2 = tx1 >> 3;
	int tx3 = tx1 / 8;
	printf("%d %d\n", tx2, tx3);

	int x1 = 65536 + 123;
	printf("%d\n", (short)x1);
}