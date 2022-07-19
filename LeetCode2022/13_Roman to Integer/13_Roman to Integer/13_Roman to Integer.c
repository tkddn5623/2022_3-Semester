#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int romanToInt(const char* s) {
	int len = strlen(s);
	int sum = 0;
	char current, next;
	for (int i = 0; i < len; i++) {
		current = s[i];
		if (i + 1 < len) next = s[i + 1];
		else next = '\0';

		switch (current) {
		case 'I':
			if (next == 'V' || next == 'X') sum -= 1;
			else sum += 1;
			break;
		case 'V':
			sum += 5;
			break;
		case 'X':
			if (next == 'L' || next == 'C') sum -= 10;
			else sum += 10;
			break;
		case 'L':
			sum += 50;
			break;
		case 'C':
			if (next == 'D' || next == 'M') sum -= 100;
			else sum += 100;
			break;
		case 'D':
			sum += 500;
			break;
		case 'M':
			sum += 1000;
			break;
		}
	}
	return sum;
}

int main()
{
	char str[] = "MCMXL";
	printf("%d\n", romanToInt(str));
}