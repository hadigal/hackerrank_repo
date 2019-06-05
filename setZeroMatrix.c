/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

void setZeroes(int** mat, int r, int* c)
{
    int **ret = (int **)malloc(r*sizeof(*ret));
    int *col  = (int *)malloc(r*sizeof(*col));

    // store the col idx of each row which has 0 value stored at that index
    for(int itr1 = 0; itr1 < r; ++itr1)
    {
        // init col array for given row to zero. this would help during making a
        // row and col of matrix zero
        col[itr1] = 0;
        for(int itr2 = 0; itr2 < c[itr1]; ++itr2)
        {
            // update the col array to store the count of col for the given row
            // where 0 was found
            if(mat[itr1][itr2] == 0)
            {
                col[itr1] += 1;
                if(col[itr1] == 1)
                {
                    ret[itr1] = (int *)malloc(col[itr1]*sizeof(int));
                }
                else
                {
                    ret[itr1] = (int *)realloc(ret[itr1],col[itr1]*sizeof(int));
                }
                ret[itr1][col[itr1]-1] = itr2;
            }
        }
    }

    for(int itr1 = 0; itr1 < r; ++itr1)
    {
        //check if total number of col for that row with zero value
        if(col[itr1] == 0)
        {
            continue;
        }

        // itr for the number of cols for that row to set the row and col elements
        // to zero in the given matrix

        // first make all the values in the col idx to 0
        for(int itr2 = 0; itr2 < col[itr1]; ++itr2)
        {
            int tmpCol = ret[itr1][itr2];
            for(int itr3 = 0; itr3 < r; ++itr3)
            {
                mat[itr3][tmpCol] = 0;
            }
        }
        // now make set the given row to zero!!
        for(int itr4 = 0; itr4 < c[itr1]; ++itr4)
        {
            mat[itr1][itr4] = 0;
        }
    }

    free(ret);
    free(col);

    return;
}
