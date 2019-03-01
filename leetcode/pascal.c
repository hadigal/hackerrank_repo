/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** generate(int numRows, int** columnSizes)
{
    int **ret;
    ret = (int **)malloc(numRows*sizeof(*ret));
    columnSizes[0] = (int *)malloc(numRows*sizeof(*columnSizes[0]));

    if(numRows == 0)
    {
        return ret;
    }


    ret[0] = (int *)malloc(1*sizeof(*ret[0]));
    ret[0][0] = 1;
    columnSizes[0][0] = 1;

    if(numRows == 1)
    {
        return ret;
    }

    uint32_t itr;

    for(itr = 1; itr < numRows; ++itr)
    {
        ret[itr] = (int *)malloc((itr+1)*sizeof(*ret[itr]));
        columnSizes[0][itr] = itr + 1;

        ret[itr][0] = 1;
        ret[itr][itr] = 1;
        size_t itr3 = 0;

        for(size_t inItr = 1; inItr < itr; ++inItr)
        {
            ret[itr][inItr] = ret[itr-1][itr3] + ret[itr-1][itr3+1];
            ++itr3;
        }
    }

    return ret;
}
