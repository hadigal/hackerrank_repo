int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize == 0)
    {
        return 0;
    }
    int len = 1;
    int itr = 0;

    while(itr < (numsSize - 1))
    {
       if(nums[itr] != nums[itr+1])
       {
           nums[len++] = nums[itr+1];
       }
       ++itr;
    }
    return len;
}
