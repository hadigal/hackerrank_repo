int findMin(int* nums, int numsSize)
{
    if(numsSize == 0)
    {
        return *nums;
    }

    if(numsSize == 1)
    {
        return nums[0];
    }

    if(nums[0] < nums[numsSize -1])
    {
        return nums[0];
    }

    uint32_t lIdx = 0, rIdx = numsSize -1, mid;

    while(lIdx <= rIdx)
    {
        mid = (lIdx + rIdx)/2;

        if(nums[mid] > nums[mid+1])
        {
            return nums[mid+1];
        }
        else if(nums[mid-1] > nums[mid])
        {
            return nums[mid];
        }

        if(nums[mid] > nums[0])
        {
            lIdx = mid+1;
        }
        else if(nums[mid] < nums[0])
        {
            rIdx = mid - 1;
        }
    }
    return -1;
}
