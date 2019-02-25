int search(int* nums, int numsSize, int target)
{
    if(numsSize == 0)
    {
        return -1;
    }

    if(numsSize == 1 && target != nums[0])
    {
        return -1;
    }


    int itr2 = numsSize - 1;
    int itr1 = 0;
    int mid = numsSize/2;

    int ret;

    while((itr1 <= (mid - 1)) && (itr2 >= mid))
    {
        if(nums[itr1] == target)
        {
            return itr1;
        }
        if(nums[itr2] == target)
        {
            return itr2;
        }
        ++itr1;
        --itr2;
    }

    if(nums[mid] == target)
    {
        return mid;
    }
    return -1;
}
