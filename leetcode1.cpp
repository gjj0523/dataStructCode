#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int main()
{
	//int nums[7] = {0,1,2,3,4,5,6};
	//int result[2] = {0};
	int* nums = (int *)malloc(sizeof(int) * 7);
	nums[0] = 0;
	nums[1] = 1;
	nums[2] = 2;
	nums[3] = 3;
	nums[4] = 4;
	nums[5] = 5;
	nums[6] = 6;
	int* result = (int *)malloc(sizeof(int) * 2);
	int target = 9;
	int length = 0;
	result = twoSum(nums,7,target,&length);
	printf("result[0] = %d   result[1] = %d",result[0],result[1]);
	return 0;
 } 
 
 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	for(int i = 0; i < numsSize; i++)
	{
		for(int j = i + 1; j < numsSize; j++)
		{
			if(nums[i] + nums[j] == target)
			{
				int* res = (int *) malloc (sizeof(int) * 2);
				res[0] = i;
				res[1] = j;
				*returnSize = 2;
				return res;
			}
		}
	}
}
