

/**
 * Note: The returned array must be malloced, assume caller calls free().
 Given an array of numbers nums, in which exactly two elements appear only once
 and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 */
int* singleNumber(int* num, int len, int* returnSize)
{
    if(num == NULL)
    {
        return num;
    }

    int *ret = (int *)calloc(2,sizeof(*ret));
    *returnSize = 2;

    int xorVal = 0;
    for(int itr = 0; itr < len; ++itr)
    {
        xorVal ^= num[itr];
    }

    int setBits = xorVal & ~(xorVal-1);

    for(int itr = 0; itr < len; ++itr)
    {
        if((setBits&num[itr]))
        {
            ret[0] ^= num[itr];
        }
        else
        {
            ret[1] ^= num[itr];
        }
    }

    return ret;
}
