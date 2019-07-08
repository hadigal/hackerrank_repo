/*
Given a sorted array nums, remove the duplicates in-place such that duplicates
appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying
the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums
being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.
Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums
being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.
Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification to
the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/


// logic is simple to iterate o(n) times and swp each element of array which are
// not repeating more than twice. This is done using 2 ptr approach where ptr idx1
// tracks the array indx to be swapped and ptr idx2 is used for iteration of the
// array
int removeDuplicates(int* arr, int len)
{
    if(len == 0)
    {
        return len;
    }

    int itr1 = 1, itr2 = 1, count = 1;

    while(itr2 < len)
    {
        if(arr[itr2] != arr[itr2-1])
        {
            arr[itr1++] = arr[itr2];
            count  = 1;
        }
        else
        {
            if(count < 2)
            {
                arr[itr1++] = arr[itr2];
                ++count;
            }
        }
        ++itr2;
    }

    return itr1;
}
