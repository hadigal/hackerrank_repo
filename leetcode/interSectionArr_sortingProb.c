/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int part(int *arr, int lIdx, int rIdx)
{
    int piv = rIdx;
    int itr1 = lIdx - 1;
    int tmp;
    int itr2;
    for(itr2 = lIdx; itr2 <= piv-1; ++itr2)
    {
        if(arr[itr2] <= arr[piv])
        {
            ++itr1;
            tmp = arr[itr1];
            arr[itr1] = arr[itr2];
            arr[itr2] = tmp;
        }
    }
    ++itr1;
    tmp = arr[itr1];
    arr[itr1] = arr[piv];
    arr[piv] = tmp;
    return itr1;
}

void quickSort(int *arr, int lIdx, int rIdx)
{
    int piv;

    if(lIdx < rIdx)
    {
        piv = part(arr,lIdx,rIdx);
        quickSort(arr,lIdx,piv-1);
        quickSort(arr,piv+1,rIdx);
    }
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{

    int *ret;
    if(nums2Size == 0 || nums1Size == 0)
    {
        *returnSize = 0;
        return ret;
    }

    quickSort(nums1,0,nums1Size-1);
    //display(nums1, nums1Size);
    quickSort(nums2,0,nums2Size-1);
    //display(nums2, nums2Size);

    int itr1 = 0;
    int itr2 = 0;

    int itr3 = 0;
    int lim;
    if(nums1Size < nums2Size)
    {
        lim = nums1Size;
    }
    else
    {
        lim = nums2Size;
    }

    ret = (int *)calloc(lim,sizeof(*ret));


    while(itr1 < nums1Size && itr2 < nums2Size)
    {
        if(nums1[itr1] == nums2[itr2])
        {
            //printf("val:%d\n",nums1[itr1]);
            ret[itr3++] = nums1[itr1];
            ++itr1;
            ++itr2;
        }
        else if(nums1[itr1] > nums2[itr2])
        {
            ++itr2;
        }
        else
        {
            ++itr1;
        }
    }
    *returnSize = itr3;
    return ret;

//     int *big, *small;
//     int bItr = 0;
//     int sItr = 0;
//     int lim;

//     if(nums2Size > nums1Size)
//     {
//         big = nums2;
//         //bItr = num2Size;
//         small = nums1;
//         lim = nums1Size;
//     }
//     else
//     {
//         big = nums1;
//         //bItr = num2Size;
//         small = nums2;
//         lim = nums2Size;
//     }

//     ret = (int *)calloc(lim,sizeof(*ret));

//     int itr3 = 0;
//     while(sItr < lim)
//     {
//         if(big[bItr] == small[sItr])
//         {
//             ret[itr3++] = small[sItr];
//             ++sItr;
//             ++bItr;
//         }
//         else if(big[bItr] > small[sItr])
//         {
//             ++sItr;
//         }
//         else
//         {
//             ++bItr;
//         }
//     }

}
