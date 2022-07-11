#include <stdio.h>



int numSubarrayProductLessThanK(int* nums, int numsSize, int k) 
{
	int count = 0, j = 0, product = nums[0];
	for (int i = 0; i < numsSize; i++) {
		if (i >= j) {
			j = i;
			product = nums[i];
		}
		while (product < k) {
			count++;
			printf("%d %d\n", i, j);
			if (j == numsSize - 1) break;
			product *= nums[++j];
			if (product >= k) {
				product /= nums[--j];
				break;
			}
		}
		
		product /= nums[i];

	}
	return count;
}

int main()
{
	int numbers[4] = { 10,5,2,6 };
	printf("%d\n", numSubarrayProductLessThanK(numbers, 4, 100));




	return 0;
}