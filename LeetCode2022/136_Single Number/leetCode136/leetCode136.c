#include <stdio.h>
#include <stdlib.h>
#define stou(s) s + 30000
int singleNumber(int* nums, int numsSize) {
	int value;
	int* counting = calloc(60001, sizeof(int));
	for (int i = 0; i < numsSize; i++) {
		counting[stou(nums[i])]++;
	}
	for (int i = 0; i < 60001; i++) {
		if (counting[i] == 1) {
			value = i - 30000;
			break;
		}
	}
	free(counting);
	return value;
}
int main()
{
	
}