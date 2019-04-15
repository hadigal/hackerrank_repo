/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int checkCount(uint8_t num)
{
    if(num == 1 || num == 2 || num == 4 || num == 8)
    {
        return 1;
    }
    else if(num == 3 || num == 5 || num == 6 || num == 9  || num == 10 || num == 12)
    {
        return 2;
    }
    else if(num == 7 || num == 11 || num == 13 || num == 14)
    {
        return 3;
    }
    else if(num == 15)
    {
        return 4;
    }
    else
    {
        return 0;
    }
}

int* countBits(int num, int* returnSize)
{
    int *arr = (int *)calloc(num+1,sizeof(*arr));
    uint8_t mask = 0xF;
    int count, temp;
    for(size_t itr = 0; itr <= num; ++itr)
    {
        temp = itr;
        count = 0;
        uint8_t val = temp & mask;
        count += checkCount(val);
        temp >>= 4;
        if(temp == 0)
        {
            arr[itr] = count;
            continue;
        }
        val = temp & mask;
        count += checkCount(val);
        temp >>= 4;
        if(temp == 0)
        {
            arr[itr] = count;
            continue;
        }
        val = temp & mask;
        count += checkCount(val);
        temp >>= 4;
        if(temp == 0)
        {
            arr[itr] = count;
            continue;
        }
        val = temp & mask;
        count += checkCount(val);
        temp >>= 4;
        if(temp == 0)
        {
            arr[itr] = count;
            continue;
        }
        val = temp & mask;
        count += checkCount(val);
        temp >>= 4;
        if(temp == 0)
        {
            arr[itr] = count;
            continue;
        }
        val = temp & mask;
        count += checkCount(val);
        temp >>= 4;
        if(temp == 0)
        {
            arr[itr] = count;
            continue;
        }
        val = temp & mask;
        count += checkCount(val);
        temp >>= 4;
        if(temp == 0)
        {
            arr[itr] = count;
            continue;
        }
        val = temp & mask;
        count += checkCount(val);
        temp >>= 4;
        if(temp == 0)
        {
            arr[itr] = count;
            continue;
        }
    }
    *returnSize = num+1;
    return arr;
}
