#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	/*char str[10];
	scanf("%s", str);
	printf("%s", str);*/
	int a;
	int ret = scanf("%d%d", &a);
	printf("%d %d\n", a, ret);
} 