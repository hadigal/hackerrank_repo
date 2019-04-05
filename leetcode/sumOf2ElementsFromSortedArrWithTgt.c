/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* arr, int numbersSize, int target, int* returnSize)
{
    int lIdx = 0;
    int rIdx = numbersSize - 1;
    int tempTgt;
    int *ret = (int *)calloc(2,sizeof(*ret));
    *returnSize = 2;

    while(lIdx < rIdx)
    {
        tempTgt = arr[lIdx] + arr[rIdx];

        if(tempTgt == target)
        {
            //printf("arr[%d]:%d\tarr[%d]:%d\n",lIdx,arr[lIdx],rIdx,arr[rIdx]);
            ret[0] = lIdx+1;
            ret[1] = rIdx + 1;
            break;
        }
        else if(tempTgt < target)
        {
            ++lIdx;
        }
        else if(tempTgt > target)
        {
            --rIdx;
        }
    }

    return ret;
}
