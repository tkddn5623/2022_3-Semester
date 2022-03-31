#include<stdio.h>
int main()
{
	char* str1 = "abcd";
	char str2[] = "abcd";

	str1[1] = 'x';
	str2[1] = 'y';

	printf("%s , %s", str1, str2);
	return 0;
}