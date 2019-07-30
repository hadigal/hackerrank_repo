/*
Given an array nums and a value val, remove all instances of that value in-place
and return the new length.

Do not allocate extra space for another array, you must do this by modifying the
input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond
the new length.

Example 1:

Given nums = [3,2,2,3], val = 3,

Your function should return length = 2, with the first two elements of nums being
2.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,1,2,2,3,0,4,2], val = 2,

Your function should return length = 5, with the first five elements of nums
containing 0, 1, 3, 0, and 4.

Note that the order of those five elements can be arbitrary.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to
the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeElement(nums, val);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/

// best algo using 2 ptr and dec the back ptr only when val at currIdx is equal
// to the given val to be removed else increment currIdx. iterate until currIdx
// is less than or equal to back ptr

int removeElement(int* nums, int numsSize, int val)
{
    int count = 0, itr = 0;
    int len = numsSize - 1;

    while(itr <= len)
    {
        if(nums[itr] == val)
        {
            nums[itr] = nums[len--];
        }
        else
        {
            //++count;
            ++itr;
        }
    }

    return (itr);
}

/*-----------------------------------------------------------------------------*/

// o(nLogn) avg case implementation not so efficient use two ptr approach
int part(int *arr, int lIdx, int rIdx, int val, int *count)
{
    int piv = rIdx;
    int itr1 = lIdx-1;
    int itr2 = lIdx;
    int tmp;

    for(; itr2 <= piv-1; ++itr2)
    {
        if(arr[itr2] != val)
        {
            ++itr1;
            tmp = arr[itr1];
            arr[itr1]=arr[itr2];
            arr[itr2] = tmp;
        }
        else
        {
            ++*count;
        }
    }

    ++itr1;
    if(arr[piv] != val)
    {
        tmp = arr[itr1];
        arr[itr1] = arr[piv];
        arr[piv] = tmp;
    }
    else
    {
        ++*count;
    }
    return itr1;
}

void qSort(int *arr, int val, int lIdx,int rIdx, int *count)
{
    if(lIdx < rIdx)
    {
        int piv = part(arr,lIdx,rIdx,val,count);
        qSort(arr,val,lIdx,piv-1,count);
        qSort(arr,val,piv+1,rIdx,count);
    }
}

void getLen(int *arr, int len, int *newLen, int val)
{
    int count = 0;
    int itr = 0;

    while(itr < len)
    {
        if(arr[itr++] == val)
        {
            ++count;
        }
    }
    //printf("---count:%d\n",count);

    *newLen = len - count;
}


int removeElement(int* nums, int numsSize, int val)
{
    if(numsSize == 0)
    {
        return 0;
    }
    int count = 0;
    qSort(nums,val,0,numsSize-1,&count);
    //printf("count:%d\n",count);
    int len = 0;
    getLen(nums,numsSize,&len,val);
    return len;
}
