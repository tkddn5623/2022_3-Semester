#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int getSum(int* subsum_t, int a, int b) {
	if (a == 0) return subsum_t[b];
	else return subsum_t[b] - subsum_t[a - 1];

}
int maxSubArray(int* nums, int numsSize)
{
	int* subsum = malloc(numsSize * sizeof(int));
	int start = 0, end, max, ret = -2147483647;

	subsum[0] = nums[0];
	max = nums[0];
	for (int i = 1; i < numsSize; i++) {
		max = max < nums[i] ? nums[i] : max; // This will get max value
		subsum[i] = subsum[i - 1] + nums[i];
		if (nums[start] <= 0 && nums[i] > 0) start = i;
	}
	if (max <= 0) {
		free(subsum);
		return max;
	}
	else {
		while (start < numsSize) { // if use for(int i = 0 ... ), time limited has occured!!
			end = start;
			for (int j = end + 1; j < numsSize; j++) {
				if (getSum(subsum, end + 1, j) >= 0) {
					end = j;
				}
			}
			for (int j = start; j < end; j++) {
				if (getSum(subsum, start, j) < 0) {
					start = j + 1;
				}
			}
			//printf("i:%d, start and end: (%d, %d)\n", i, start, end);
			ret = ret < getSum(subsum, start, end) ? getSum(subsum, start, end) : ret;
			start = end + 1;
		}

	}
	//ret = getSum(subsum, start, end);
	free(subsum);
	return ret;
}

int arr[100000];
int main()
{
	//int arr[] = { -2,1,-3,4,-1,2,1,-5,4 };
	//int arr[] = { 3, -2, -3, -3, 1, 3, 0 };
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &arr[i]);
	}
	printf("%d\n", maxSubArray(arr, a));
}