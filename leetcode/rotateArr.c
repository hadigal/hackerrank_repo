static inline void rev(int *ptr1, int *ptr2)
{
    *ptr1 = *ptr1 ^ *ptr2;
    *ptr2 = *ptr2 ^ *ptr1;
    *ptr1 = *ptr1 ^ *ptr2;
}

static inline void rArr(int *num, int start, int end)
{
    while(start < end)
    {
        rev(num+start,num+end);
        ++start;
        --end;
    }
}


// here use inplace rotate i.e without extra space!!
void rotate(int* num, int len, int k)
{
    if(k == len)
    {
        return;
    }

    //check if k is > len; if so get diff of k and len
    k = (k > len)?(k-len):k;

    // now reverse the entire array
    // after reverse reverse the first k elements of array
    // then reverse the k to len-1 elements of the array
    rArr(num,0,len-1);
    rArr(num,0,k-1);
    rArr(num,k,len-1);
}


// this approach uses extra space o(n)
// first store the len-k to len-1 elements in new array
// then store the remaining elements from 0 to len - k - 2 at the remaining index
// of the new array


// void rotate(int* num, int len, int k)
// {
//     if(k == len)
//     {
//         return;
//     }

//     k = (k > len)?(k-len):k;

//     int *arr = (int *)malloc(len*sizeof(*arr));
//     int idx = 0;
//     int itr = len - k;

//     while(itr < len && idx < k)
//     {
//         arr[idx++] = num[itr++];
//     }

//     itr = 0;
//     while(idx < len)
//     {
//         arr[idx++] = num[itr++];
//     }

//     itr = 0;
//     while(itr < len)
//     {
//         num[itr] = arr[itr];
//         ++itr;
//     }
//     free(arr);
// }
