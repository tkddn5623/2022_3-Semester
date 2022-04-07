#include<stdio.h>
int main()
{
	char* str1 = "abcde";
	char str2[] = "abcde";

	//str1[0] = 'a';
	//str1[1] = 'x';
	str2[1] = 'y';

	printf("%s , %s\n", str1, str2);
	printf("%c , %c\n", str1[1], str2[1]);
	printf("%d , %d\n", sizeof(str1), sizeof(str2));
	return 0;
}