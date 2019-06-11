/*
Given an array nums, write a function to move all 0's to the end of
it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

static inline void swp(int *ptr1, int *ptr2)
{
    *ptr1 = *ptr1 ^ *ptr2;
    *ptr2 = *ptr1 ^ *ptr2;
    *ptr1 = *ptr2 ^ *ptr1;
}

void moveZeroes(int* nums, int len)
{
    // 2 ptr appraoch used
    int idx1 = 0;
    int idx2 = idx1+1;

    // check if ptr1 and ptr2 are both zeros 1st if so move ptr2 only continue
    // if not then check if ptr1 is zero and other is not; swp ptr1 and ptr2
    // increment both ptr1 and ptr2
    while(idx1 < (len-1) && idx2 < len && idx1 < idx2)
    {
        if(nums[idx1] == 0 && nums[idx2] == 0)
        {
            ++idx2;
            continue;
        }
        else if(nums[idx1] == 0 && nums[idx2] != 0)
        {
            swp(nums+idx1,nums+idx2);
        }

        ++idx1;
        ++idx2;
    }
}
