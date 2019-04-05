int searchInsert(int* arr, int numsSize, int target)
{
    int mid;
    int lIdx = 0;
    int rIdx = numsSize - 1;

    if(target < arr[lIdx])
    {
        return 0;
    }
    else if(target > arr[rIdx])
    {
        return numsSize;
    }

    while(lIdx <= rIdx)
    {
        mid = (lIdx+rIdx)/2;

        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            lIdx = mid+1;
            rIdx = rIdx;
        }
        else if(arr[mid] > target)
        {
            lIdx = lIdx;
            rIdx = mid-1;
        }
    }

    return lIdx;
    //int ret;
    // while(lIdx <= rIdx)
    // {
    //     if(arr[lIdx] > target)
    //     {
    //         return (lIdx-1);
    //     }
    //     ++lIdx;
    // }
    // return (rIdx+1);
}
