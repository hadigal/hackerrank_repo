/*
Given n non-negative integers representing an elevation map where the width
of each bar is 1, compute how much water it is able to trap after raining.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.

Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

*/


// logic is to find the left and right max heights for each idx and compute
// the water trapped at each idx by sub value(height) at the given index with
// min(left_height_max_at_that_idx, right_height_max_at_that_idx)

int trap(int* height, int size)
{
    if(height == NULL || size == 0)
    {
        return 0;
    }

    // store the max left and right heights for each index in an array
    int *left = (int *)malloc(size*sizeof(*left));
    int *right = (int *)malloc(size*sizeof(*right));
    int store = 0;
    int tmp;

    // start with left max height; for 0th index there is no left height so its
    // own value is its max height
    left[0] = height[0];

    // iterate from idx 1 to n-1 compare current idx height with previous idx max height
    // if current height is > prev_idx_maxHeight store that value in left_max array at
    // given idx else store the prev idx max height at current idx
    for(int itr = 1; itr < size; ++itr)
    {
        left[itr] = (left[itr-1] > height[itr])?left[itr-1]:height[itr];
    }

    // similarly for right max height; since we are considering the right heights
    // we start from the right most idx;
    right[size-1] = height[size-1];
    for(int itr = size-2; itr >= 0; --itr)
    {
        right[itr] = (right[itr+1] > height[itr])?right[itr+1]:height[itr];
    }

    // now get the min of left and right height for given idx and subtract the value
    // with actual height of that idx; this gives the info about the water trapped at
    // that idx!!
    for(int itr = 0; itr < size; ++itr)
    {
        tmp = (left[itr] < right[itr])?left[itr]:right[itr];
        store += (tmp - height[itr]);
    }

    free(left);
    free(right);
    return store;
}
