/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/

int cmp(const void *ptr1, const void *ptr2)
{
    int val1 = *(int *)ptr1;
    int val2 = *(int *)ptr2;

    if(val1 < val2)
    {
        return -1;
    }
    else if(val1 == val2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int firstMissingPositive(int* nums, int len)
{
    int itr = 0;
    int small = 1;
    qsort(nums,len,sizeof(*nums),cmp);

    while(itr < len)
    {
        if(small == nums[itr])
        {
            ++small;
        }
        ++itr;
    }

    return small;
}
