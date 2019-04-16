/****************************** My solution *********************************
Iterating row wise checking if start of curr row is <= tgt and tgt <= end of curr
row. If so appy binary search on that row and return true.; else return false from
helper function!
*****************************************************************************/
bool search(int *arr, int len, int tgt)
{
    if(arr[0] <= tgt && tgt <= arr[len-1])
    {
        int lt = 0;
        int rt = len -1;
        int mid;
        while(lt <= rt)
        {
            mid = (lt+rt)/2;
            if(arr[mid] == tgt)
            {
                return true;
            }
            else
            {
                if(arr[mid] < tgt)
                {
                    lt = mid+1;
                }
                else
                {
                    rt = mid - 1;
                }
            }
        }
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int *matrixColSizes, int target)
{
    if(matrixRowSize == 0 || matrixColSizes[0] == 0)
    {
        return false;
    }

    int col = matrixColSizes[0];
    bool val = false;
    int itr = 0;

    while(itr < matrixRowSize && val == false)
    {
        val = search(*(matrix+itr),col,target);
        ++itr;
    }

    return val;
}

/******************** solution to virtually convert 2D array in a (row x col - 1)
array. The idea is to apply binary search on the virtual array or the 2D array as whole
Here we findd piv which depicts the mid index in the virtual array using mid we find
the row and col of matrix. col = piv % col; row = piv / col;
*******************************************************************************

bool searchMatrix(int** matrix, int matrixRowSize, int *matrixColSizes, int target)
{
    if(matrixRowSize == 0)
    {
        return false;
    }

    int32_t lt = 0;
    int32_t col = matrixColSizes[0];
    int32_t rt = matrixRowSize * col - 1;
    int32_t piv;

    while(lt <= rt)
    {
        int tempR, tempC;
        piv = (lt+rt)/2;
        tempR = piv/col;
        tempC = piv%col;
        if(matrix[tempR][tempC] == target)
        {
            return true;
        }
        else if(matrix[tempR][tempC] < target)
        {
            lt = piv + 1;
        }
        else if(matrix[tempR][tempC] > target)
        {
            rt = piv - 1;
        }
    }

    return false;
}
******************************************************************************/
