#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define XXX 13

int pw3(int n)
{
	int r = 1;
	for (int i = 0; i < n; i++)
		r = r * 3;
	return r;
}
long long pw7(int n)
{
	long long r = 1;
	for (int i = 0; i < n; i++)
		r = r * 7;
	return r;
}
/*int getLarge(int n)
{
	for (int i = 13; i >= 0; i--)
		if (n >= pw7(i))
			return i;
	return -1;
}*/
int cal(long long int input)
{
	int level = 0;
	int slot[XXX] = { 0 };
	//int large = getLarge(input);
	for (int i = XXX-1; i >= 0; i--) {
		if (input >= pw7(i)) {
			slot[i]++;
			input = input - pw7(i);
			if (input >= pw7(i)) {
				slot[i]++;
				input = input - pw7(i);
			}
		}
	}
	for (int i = 0; i < XXX; i++) {
		//printf("i and level %d %d\n", i, level);
		level = level + slot[i] * pw3(i);
	}
	for (int i = 0; i < 7; i++) {
		//printf("%d ", slot[i]);
	}
	//puts("");
	//printf("l is %d\n", large);
	//if (slot[large] == 1) level--;
	return level;
	
}
int main()
{
	long long int input;
	scanf("%lld", &input);
	printf("%d\n", cal(input));

}
//clear...