/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void *aptr1, const void *aptr2)
{
   return (*(int *)aptr1 - *(int *)aptr2);
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
    qsort(nums,numsSize,sizeof(int),compare);
    int **arr = (int **)calloc(1,sizeof(*arr));
    int len = numsSize - 1;
    int currItr = 0;

    int lIdx, rIdx, sum, itr1;
    for(itr1 = 0; itr1 < len - 1; ++itr1)
    {
        if(itr1 == 0 || (itr1 > 0 && (nums[itr1] != nums[itr1 - 1])))
        {
            lIdx = itr1+1;
            rIdx = len;
            sum = 0 - nums[itr1];
            while(lIdx < rIdx)
            {
                if((nums[lIdx] + nums[rIdx]) == sum)
                {
                    if(currItr != 0)
                    {
                        arr = (int **)realloc(arr,(currItr+1)*sizeof(*arr));
                    }

                    arr[currItr] = (int *)calloc(3,sizeof(*arr[currItr]));
                    arr[currItr][0] = nums[itr1];
                    arr[currItr][1] = nums[lIdx];
                    arr[currItr][2] = nums[rIdx];
                    ++currItr;
                    while((lIdx < rIdx) && (nums[lIdx] == nums[lIdx + 1]))
                    {
                        lIdx++;
                    }

                    while((lIdx < rIdx) && (nums[rIdx] == nums[rIdx - 1]))
                    {
                        --rIdx;
                    }
                    ++lIdx;
                    --rIdx;
                }
                else if((nums[lIdx] + nums[rIdx]) < sum)
                {
                    ++lIdx;
                }
                else if((nums[lIdx] + nums[rIdx]) > sum)
                {
                    --rIdx;
                }
            }
        }
    }

    *returnSize = currItr;
    return arr;
}
