/*
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime?
You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* num, int len, int* retSize)
{
    int *ret = (int *)malloc((len+1)*sizeof(*ret));
    int itr = 0;
    memset(ret,0,(len+1)*(sizeof(*ret)));
    *retSize = 0;

    while(itr < len)
    {
        ret[num[itr++]] += 1;
    }

    itr = 1;
    while(itr <= len)
    {
        if(ret[itr] == 0)
        {
            ret[*retSize] = itr;
            *retSize += 1;
        }
        ++itr;
    }

    return ret;
}
