#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void moveZeroes(int* nums, int numsSize) {
	int* nums_temp = calloc(numsSize, sizeof(int));
	//int index = 0;
	for (int i = 0, index = 0; i < numsSize; i++) {
		if (nums[i] != 0) nums_temp[index++] = nums[i];
	}
	memcpy(nums, nums_temp, numsSize * sizeof(int));
	free(nums_temp);
}

int main() {
	int* nums = calloc(5, sizeof(int));
	nums[0] = 0;
	nums[1] = 1;
	nums[2] = 0;
	nums[3] = 3;
	nums[4] = 12;
	moveZeroes(nums, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d\n", nums[i]);
	}
	free(nums);
}