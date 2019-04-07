/** solution using flyod's cycle algo. this works because numbers are from 1 to
n+1 in an array of n elements **/
int findDuplicate(int* nums, int numsSize)
{
    //qSort(nums,0,numsSize-1);

    int fast = nums[0];
    int slow = nums[0];

    do
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
    }while(fast != slow);

    int ptr1 = nums[0];
    int ptr2 = slow;

    while(ptr1 != ptr2)
    {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }

    // int itr = 0;
    // while(itr < numsSize-1)
    // {
    //     if(nums[itr] == nums[itr+1])
    //     {
    //         return nums[itr];
    //     }
    //     ++itr;
    // }
    //return 0;

    return ptr1;
}

/** solution using qsort algo **/
int part(int *arr, int lIdx, int rIdx)
{
    int piv = rIdx;
    int itr1;
    int itr2 = lIdx -1;
    int temp;

    for(itr1 = lIdx; itr1 <= piv-1; ++itr1)
    {
        if(arr[itr1] <= arr[piv])
        {
            ++itr2;
            temp = arr[itr1];
            arr[itr1] = arr[itr2];
            arr[itr2] = temp;
        }
    }

    ++itr2;
    temp = arr[itr2];
    arr[itr2] = arr[piv];
    arr[piv] = temp;

    return itr2;
}

void qSort(int *arr, int lIdx, int rIdx)
{
    int piv;

    if(lIdx < rIdx)
    {
        piv = part(arr, lIdx,rIdx);
        qSort(arr,lIdx, piv-1);
        qSort(arr,piv+1,rIdx);
    }
    return;
}

int findDuplicate(int* nums, int numsSize)
{
    qSort(nums,0,numsSize-1);

    int itr = 0;
    while(itr < numsSize-1)
    {
        if(nums[itr] == nums[itr+1])
        {
            return nums[itr];
        }
        ++itr;
    }
    return 0;
}
