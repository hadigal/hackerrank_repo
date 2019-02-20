/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void adjustArr(int *arr, int len)
{
    int itr = 0;

    int tempOut  = arr[0];
    int newLen  = len -1;
    while(itr < newLen)
    {
        int temp = arr[itr+1];
        arr[itr+1] = tempOut;
        tempOut = temp;
        ++itr;
    }
}

int *addNewArrIdx(int *newArr, int digitsSize, int itr, int *returnSize)
{
    int sizeArr = digitsSize + 1;
    newArr = (int *)realloc(newArr,(sizeArr)*sizeof(int));
    adjustArr(newArr,(digitsSize+1));
    newArr[itr+1] = 1;
    *returnSize = (*returnSize) + 1;
    return newArr;
}

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int *newArr = (int *)calloc(digitsSize,sizeof(*newArr));
    int itr = digitsSize -1;
    int lastDig = digits[itr];
    *returnSize = digitsSize;

    while(itr >= 0)
    {
        if(lastDig == 9 && itr == (digitsSize -1))
        {
            newArr[itr--] = 0;
            if(itr < 0)
            {
                newArr = addNewArrIdx(newArr,digitsSize, itr, returnSize);
                continue;
            }
            newArr[itr] = 1;
            continue;
        }
        else if(lastDig != 9 && itr == (digitsSize -1))
        {
            newArr[itr--] = lastDig + 1;
            continue;
        }

        if((newArr[itr]+digits[itr]) >= 10)
        {
            int temp = (newArr[itr]+digits[itr])%10;
            newArr[itr--] = temp;
            if(itr < 0)
            {
                newArr = addNewArrIdx(newArr,digitsSize, itr, returnSize);
                continue;
            }
            newArr[itr] = 1;
            continue;
        }
        else
        {
            newArr[itr] += digits[itr];
            --itr;
            continue;
        }
    }
    return newArr;
}
