/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/

// quick sort logic
// here logic is to compare the string at given idx with str at piv; if
// the str[idx] > str[piv] only then move the string numbers.
int part(char **str, int *len, int lIdx, int rIdx)
{
    int piv = rIdx;
    int itr1 = lIdx -1;
    int itr2 = lIdx;

    for(; itr2 <= piv - 1; ++itr2)
    {
        if(strcmp(str[itr2],str[piv]) > 0)
        {
            ++itr1;
            char *tmp = str[itr1];
            str[itr1] = str[itr2];
            str[itr2] = tmp;

            int t = len[itr1];
            len[itr1] = len[itr2];
            len[itr2] = t;
        }
    }

    ++itr1;
    char *tmp = str[itr1];
    str[itr1] = str[piv];
    str[piv] = tmp;

    int t = len[itr1];
    len[itr1] = len[piv];
    len[piv] = t;

    return itr1;
}

void qSort(char **str,int *len, int lIdx, int rIdx)
{
    int piv;
    if(lIdx < rIdx)
    {
        piv = part(str,len,lIdx,rIdx);
        qSort(str,len,lIdx,piv-1);
        qSort(str,len,piv+1,rIdx);
    }
}

// logic is first to convert all ints to string. Once the numbers are converted
//to string sort the stringized numbers lexographically using strcmp and quick
// sort algo in descending order. Once the stringized numbers are sorted now
// do a string concat of str[idx]and str[idx+1]and compare with str[idx+1]and
//str[idx]. Now move the strings accordingly if either of the one is greater in
// combination. Use a flg to check if every combination is proper descending order.
char * largestNumber(int* nums, int numsSize)
{
    if(numsSize == 0)
    {
        return NULL;
    }

    char **strNum = (char **)malloc(numsSize*sizeof(*strNum));
    int itr = 0, size = 0;
    int *len = (int *)malloc(numsSize*sizeof(*len));
    char *ret = NULL;
    int strItr = 0, zc = 0, idx = 0;
    bool flg = false;

    while(itr < numsSize)
    {
        strNum[itr] = (char *)malloc(10*sizeof(char));
        snprintf(strNum[itr],10,"%d",nums[itr]);
        len[itr] = strlen(strNum[itr]);
        size += len[itr];
        ++itr;
    }

    qSort(strNum,len,0,numsSize-1);
    itr = 0;

    while(itr < numsSize-1)
    {
        int tmpLen = len[itr]+len[itr+1]+1;
        char *tmp1 = (char *)malloc((tmpLen)*sizeof(tmp1));
        snprintf(tmp1,tmpLen,"%s%s",strNum[itr],strNum[itr+1]);

        char *tmp2 = (char *)malloc((tmpLen)*sizeof(tmp2));
        snprintf(tmp2,tmpLen,"%s%s",strNum[itr+1],strNum[itr]);

        if(strcmp(tmp1,tmp2) < 0)
        {
            char *tmp = strNum[itr];
            strNum[itr] = strNum[itr+1];
            strNum[itr+1] = tmp;
            int t = len[itr];
            len[itr] = len[itr+1];
            len[itr+1] = t;
            if(flg == false)
            {
                idx = itr-1;
                idx = (idx >= 0)?idx:0;
                flg = true;
            }
        }
        ++itr;

        if(flg == true && itr == numsSize - 1)
        {
            // itr = 0;
            itr = idx;
            flg = false;
            continue;
        }
    }

    itr = 0;
    ret = (char *)malloc((size+1)*sizeof(*ret));

    while(itr < numsSize)
    {
        if(strcmp(strNum[itr],"0") == 0)
        {
            ++zc;
        }
        snprintf(ret+strItr,len[itr]+1,"%s",strNum[itr]);
        strItr += len[itr];
        free(strNum[itr]);
        ++itr;
    }

    if(zc == numsSize)
    {
        ret[1] = '\0';
    }
    free(strNum);
    free(len);

    return ret;
}
