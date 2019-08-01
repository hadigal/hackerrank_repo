/*
Given a n x n matrix where each of the rows and columns are sorted in ascending
order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth
distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/

int cmp(const void *ptr1, const void *ptr2)
{
    int val1 = *(int *)ptr1;
    int val2 = *(int *)ptr2;

    return (val1 - val2);
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k)
{
    int len = matrixSize*matrixSize;
    int *arr = (int *)malloc(len*sizeof(*arr));
    int idx = 0, ret;
    for(int itr1 = 0; itr1 < matrixSize; ++itr1)
    {
        for(int itr2 = 0; itr2 < matrixSize; ++itr2)
        {
            arr[idx] = matrix[itr1][itr2];
            ++idx;
        }
    }

    qsort(arr,len,sizeof(*arr),cmp);
    ret = arr[k-1];

    free(arr);
    return ret;
}
