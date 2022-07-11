#include <stdio.h>
#include <stdlib.h>

int compare(const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int singleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    if (numsSize >= 2 && nums[0] != nums[1])
        return nums[0];
    for (int i = 1; i < numsSize - 2; i++) {
        if (nums[i] != nums[i + 1] && nums[i + 1] != nums[i + 2])
            return nums[i + 1];
    }
    if (numsSize >= 2 && nums[numsSize - 2] != nums[numsSize - 1])
        return nums[numsSize - 1];
    return nums[0];
}

int main()
{
	int arr[] = { 2,2,3,2 };
    printf("%d\n", singleNumber(arr, sizeof(arr) / sizeof(int)));
}