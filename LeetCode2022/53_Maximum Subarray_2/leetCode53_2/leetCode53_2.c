#include <stdio.h>
#include <stdlib.h>

int subAnswer[100000];
int maxSubArray(int* nums, int numsSize) 
{
	//int* subAnswer = malloc(numsSize * sizeof(int));
	int ret = nums[0];
	subAnswer[0] = nums[0];
	for (int i = 0; i < numsSize - 1; i++) {
		subAnswer[i + 1] = subAnswer[i] < 0 ? nums[i + 1] : subAnswer[i] + nums[i + 1];
		ret = ret < subAnswer[i + 1] ? subAnswer[i + 1] : ret;
	}
	//free(subAnswer);
	//printf("%d\n", ret);
	return ret;
}
int main()
{
	int nums[] = { 3, -2, -3, -3, 1, 3, 0 };
	maxSubArray(nums, sizeof(nums) / sizeof(int));
}