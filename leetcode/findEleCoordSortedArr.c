/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *ret = (int *)calloc(2,sizeof(*ret));
    *returnSize = 2;

    if(numsSize == 0)
    {
        ret[0] = -1;
        ret[1] = -1;

        return ret;
    }

    int mid = numsSize/2;
    int stFlg = -1;
    int spFlg = -1;

    int itr;

    if(target <= nums[mid])
    {
        itr = 0;
        while(itr <= (mid - 1))
        {
            if((stFlg == -1) && (nums[itr] == target))
            {
                stFlg = itr;
                spFlg = itr;
            }
            if((stFlg != -1) && (nums[itr] == target))
            {
                spFlg = itr;
            }
            if((spFlg != -1) && nums[itr] != target)
            {
                ret[0] = stFlg;
                ret[1] = spFlg;
                return ret;
            }
            ++itr;
        }
    }

    if(target >= nums[mid])
    {
        itr = mid;
        while(itr <= (numsSize - 1))
        {
            if((stFlg == -1) && (nums[itr] == target))
            {
                //printf("---->%d\n",stFlg);
                stFlg = itr;
                spFlg = itr;
            }
            if((stFlg != -1) && (nums[itr] == target))
            {
                spFlg = itr;
            }
            if((spFlg != -1) && nums[itr] != target)
            {
                ret[0] = stFlg;
                ret[1] = spFlg;
                return ret;
            }
            ++itr;
        }
    }

    //printf("stFlg:%d\n",stFlg);
    ret[0] = stFlg;
    ret[1] = spFlg;
    return ret;
}
