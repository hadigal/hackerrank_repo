/***************************************************
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
****************************************************/

bool search(int* nums, int numsSize, int target)
{
    if(numsSize == 1)
    {
        if(nums[0] == target)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(numsSize == 0)
    {
        return false;
    }

    int start;
    int mid;
    int lIdx,rIdx;
    uint8_t itrFlg = 0;

    uint32_t itr = 0;
    bool flg = false;
    while(itr < numsSize - 1)
    {
        if(nums[itr] == target)
        {
            flg = true;
        }
        else if(nums[itr] > nums[itr+1])
        {
            start = itr+1;
            lIdx = start;
            rIdx = numsSize-1;
            while(lIdx <= rIdx)
            {
                if(itrFlg == 0)
                {
                    itrFlg = 1;
                }
                mid = (lIdx+rIdx)/2;

                if(nums[mid] == target)
                {
                    flg = true;
                    break;
                }
                else if(nums[mid] < target)
                {
                    lIdx = mid+1;
                    rIdx = rIdx;
                }
                else if(nums[mid] > target)
                {
                    lIdx = lIdx;
                    rIdx = mid-1;
                }
            }
        }


        if(flg ==  true)
        {
            break;
        }
        else if(itrFlg == 1)
        {
            break;
        }
        ++itr;
    }

    if(flg == false && itrFlg == 0 && (itr == (numsSize - 1)))
    {
        //printf("itr:%d\n",itr);
        if(nums[itr] == target)
        {
            return true;
        }
    }

    return flg;
}
