/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
*/

 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

// otpimized solution
 int* findDuplicates(int* num, int len, int* retSize)
 {
     int *ret = (int *)malloc(len*sizeof(*ret));
     int idx, itr = 0;
     *retSize = 0;

     while(itr < len)
     {
         idx = abs(num[itr]) - 1;
         if(num[idx] < 0)
         {
             ret[*retSize] = idx+1;
             *retSize += 1;
         }
         num[idx] *= -1;
         ++itr;
     }

     return ret;
 }


 // not so optimum solution; using extra space to store the elements in the array.
int* findDuplicates(int* arr, int len, int* retSize)
{
    if(len == 0)
    {
        *retSize = 0;
        return NULL;
    }

    int *tmp = (int *)malloc((len+1)*sizeof(*tmp));
    memset(tmp,0,len*(sizeof(*tmp)));
    int *ret = (int *)malloc(1*sizeof(*ret));
    *retSize = 0;

    int itr = 0;

    while(itr < len)
    {
        if(tmp[arr[itr]] == 1)
        {
            if(*retSize > 0)
            {
                ret = (int *)realloc(ret,sizeof(*ret)*(*retSize+1));
            }
            ret[*retSize] = arr[itr];
            *retSize += 1;
        }
        else
        {
            tmp[arr[itr]] = 1;
        }

        ++itr;
    }

    free(tmp);
    return ret;
}
