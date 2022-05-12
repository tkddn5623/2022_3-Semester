#include <stdio.h>



int numSubarrayProductLessThanK(int* nums, int numsSize, int k) 
{
	int count = 0, j = 0, product = 1;
	for (int i = 0; i < numsSize; i++) {
		if ((j = j <= i ? i : j) <= i) 
			product = 1;
		while (j < numsSize && product * nums[j] < k)
			product *= nums[j++];
		count += j - i;
		product /= nums[i];
	}
	return count;
}

int main()
{
	int numbers[4] = { 1,5,2,2 };
	printf("%d\n", numSubarrayProductLessThanK(numbers, 4, 100));




	return 0;
}