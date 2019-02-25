void merge(int* nums1, int m, int* nums2, int n)
{
    if(n == 0)
    {
        return;
    }
    else if(m == 0)
    {
        int itr = 0;
        while(itr < n)
        {
            nums1[itr] = nums2[itr];
            ++itr;
        }
        return;
    }

    int newLen = m+n;
    int itr1 = 0;
    int itr2 = 0;
    int itr3 = 0;
    int *arr3 = (int *)calloc(newLen,sizeof(*arr3));

    int flg1 = 0;
    int flg2 = 0;

    while(itr1 < m && itr2 < n)
    {
        if(nums1[itr1] > nums2[itr2])
        {
            arr3[itr3++] = nums2[itr2++];
        }
        else if(nums1[itr1] < nums2[itr2])
        {
            arr3[itr3++] = nums1[itr1++];
            //arr3[itr3++] = nums2[itr2++];
        }
        else
        {
            arr3[itr3++] = nums1[itr1++];
            arr3[itr3++] = nums2[itr2++];
        }
    }

    while(itr1 < m)
    {
        arr3[itr3++] = nums1[itr1++];
    }

    while(itr2 < n)
    {
        arr3[itr3++] = nums2[itr2++];
    }

    int temp = 0;
    while(temp < newLen)
    {
        nums1[temp] = arr3[temp];
        ++temp;
    }

    free(arr3);
    return;
}
