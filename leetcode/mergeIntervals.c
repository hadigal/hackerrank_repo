

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int part(int **arr, int lIdx, int rIdx)
{
    int piv = rIdx;
    int itr1 = lIdx-1,itr2;

    for(itr2 = lIdx; itr2 <= piv -1; ++itr2)
    {
        if(arr[itr2][0] <= arr[piv][0])
        {
            ++itr1;
            int tmp1 = arr[itr2][0];
            int tmp2 = arr[itr2][1];
            arr[itr2][0] = arr[itr1][0];
            arr[itr2][1] = arr[itr1][1];

            arr[itr1][0] = tmp1;
            arr[itr1][1] = tmp2;
        }
    }

    ++itr1;
    int tmp1 = arr[piv][0];
    int tmp2 = arr[piv][1];
    arr[piv][0] = arr[itr1][0];
    arr[piv][1] = arr[itr1][1];

    arr[itr1][0] = tmp1;
    arr[itr1][1] = tmp2;

    return itr1;
}

void qSort(int **arr, int lIdx, int rIdx)
{
    int piv;
    if(lIdx <= rIdx)
    {
        piv = part(arr,lIdx,rIdx);
        qSort(arr,lIdx,piv-1);
        qSort(arr,piv+1,rIdx);
    }
}


// logic is to sort the intervals first using the start value of each interval. Then
// merge the intervals based on the last value of given interval and its subsequent
// intervals.
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
    if(intervalsSize == 0 || intervalsSize == 1)
    {
        *returnSize = intervalsSize;
        return intervals;
    }

    qSort(intervals,0,intervalsSize-1);

    while(1)
    {
        int itr1 = 0, itr2, max;
        bool flg = false;
        *returnSize = 0;

        while(itr1 < intervalsSize)
        {
            if(intervalsColSize[itr1] == 0)
            {
                continue;
            }

            intervals[*returnSize][0] = intervals[itr1][0];
            max = intervals[itr1][1];
            itr2 = itr1 + 1;


            while(itr2 < intervalsSize && (intervals[itr1][0] == intervals[itr2][0] || intervals[itr1][1] >= intervals[itr2][0]))
            {
                if(intervals[itr2][1] > max)
                {
                    max = intervals[itr2][1];
                    flg = true;
                }
                ++itr2;
            }

            intervals[*returnSize][1] = max;

            ++*returnSize;
            itr1 = itr2;
        }

        if(flg == false)
        {
            break;
        }
        intervalsSize = *returnSize+1;
    }

    *returnColumnSizes = intervalsColSize;
    return intervals;
}
