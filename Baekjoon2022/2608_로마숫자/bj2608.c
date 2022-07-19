#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
	char* str = calloc(16, sizeof(char));
	int idx = 0;
	int pivot;

	pivot = num / 1000;
	num %= 1000;
	while (pivot > 0) {
		str[idx++] = 'M';
		pivot--;
	}

	pivot = num / 100;
	num %= 100;
	switch (pivot) {
	case 1:
	case 2:
	case 3:
		for (int i = 0; i < pivot; i++)
			str[idx++] = 'C';
		break;
	case 4:
		str[idx++] = 'C';
		str[idx++] = 'D';
		break;
	case 5:
	case 6:
	case 7:
	case 8:
		str[idx++] = 'D';
		for (int i = 0; i < pivot - 5; i++)
			str[idx++] = 'C';
		break;
	case 9:
		str[idx++] = 'C';
		str[idx++] = 'M';
	}

	pivot = num / 10;
	num %= 10;
	switch (pivot) {
	case 1:
	case 2:
	case 3:
		for (int i = 0; i < pivot; i++)
			str[idx++] = 'X';
		break;
	case 4:
		str[idx++] = 'X';
		str[idx++] = 'L';
		break;
	case 5:
	case 6:
	case 7:
	case 8:
		str[idx++] = 'L';
		for (int i = 0; i < pivot - 5; i++)
			str[idx++] = 'X';
		break;
	case 9:
		str[idx++] = 'X';
		str[idx++] = 'C';
	}

	pivot = num;
	switch (pivot) {
	case 1:
	case 2:
	case 3:
		for (int i = 0; i < pivot; i++)
			str[idx++] = 'I';
		break;
	case 4:
		str[idx++] = 'I';
		str[idx++] = 'V';
		break;
	case 5:
	case 6:
	case 7:
	case 8:
		str[idx++] = 'V';
		for (int i = 0; i < pivot - 5; i++)
			str[idx++] = 'I';
		break;
	case 9:
		str[idx++] = 'I';
		str[idx++] = 'X';
	}
	return str;
}
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

int main() {
	int sum;
	char str1[16];
	char str2[16];
	char* str3;

	scanf("%s %s", str1, str2);
	sum = romanToInt(str1) + romanToInt(str2);
	str3 = intToRoman(sum);

	printf("%d\n%s\n", sum, str3);
	free(str3);
}