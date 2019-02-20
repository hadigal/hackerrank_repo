/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void adjustArr(int *arr, int len)
{
    int itr = 1;
    int tempOut  = arr[0];
    int newLen  = len -1;
    while(itr < newLen)
    {
        int temp = arr[itr+1];
        arr[itr] = tempOut;
        tempOut = temp;
    }
}

void addNewArrIdx(int *newArr, int digitSize, int itr, int *returnSize)
{
    newArr = (int *)realloc(newArr,(digitSize+1)*sizeof(*newArr));
    adjustArr(newArr,(digitSize+1));
    newArr[itr+1] = 1;
    *returnSize = *returnSize + 1;
}

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int *newArr = (int *)calloc(digitsSize,sizeof(*newArr));
    int itr = digitSize -1;
    int lastDig = digits[itr];
    *returnSize = digitSize;

    while(itr >= 0)
    {
        if(lastDig == 9 && itr == (digitsSize -1))
        {
            newArr[itr--] = 0;
            newArr[itr] = 1;
            if(itr < 0)
            {
                // newArr = (int *)realloc(newArr,(digitSize+1)*sizeof(*newArr));
                // adjustArr(newArr,(digitSize+1));
                // newArr[itr+1] = 1;
                // *returnSize = *returnSize + 1;
                addNewArrIdx(newArr,digitSize, itr, returnSize);
                continue;
            }
            continue;
        }

        if((newArr[itr]+arr[itr]) >= 10)
        {
            int temp = (newArr[itr]+arr[itr])%10;
            newArr[itr--] = temp;
            if(itr < 0)
            {
                // newArr = (int *)realloc(newArr,(digitSize+1)*sizeof(*newArr));
                // adjustArr(newArr,(digitSize+1));
                // newArr[itr+1] = 1;
                // *returnSize = *returnSize + 1;
                addNewArrIdx(newArr,digitSize, itr, returnSize);
                continue;
            }
            newArr[itr] = 1;
            continue;
        }
        else
        {
            newArr[itr] = arr[itr];
            --itr;
            continue;
        }
    }
    return newArr;
}
