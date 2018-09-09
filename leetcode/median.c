#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
  int mid,tlen,lim,mid2;
  if(nums1Size == 0)
  {
    if(nums2Size%2 == 0)
    {
      mid = (int)(nums2Size/2);
      double ret = ((double)(nums2[mid]+nums2[mid-1]))/2;
      return ret;
    }
    else
    {
      mid = (int)ceil((float)(nums2Size)/2);
      return (double)nums2[mid-1];
    }
  }
  else if(nums2Size == 0)
  {
    if(nums1Size%2 == 0)
    {
      mid = (int)(nums1Size/2);
      double ret = ((double)(nums1[mid]+nums1[mid-1]))/2;
      return ret;
    }
    else
    {
      mid = (int)ceil((float)(nums1Size)/2);
      return (double)nums1[mid-1];
    }
  }

  tlen = nums1Size+nums2Size;
  int *medianArr = (int *)malloc(tlen*sizeof(*medianArr));
  if(tlen%2 == 0)
  {
    mid = (int)(tlen/2);
    mid2 = mid+1;
    lim = mid2;
  }
  else
  {
    mid = (int)ceil((float)(tlen)/2);
    lim = mid;
  }

  int itr1 = 0, itr2 = 0, itr3 =0,itr4 = 0, len1, len2;
  int *max,*min;
  if(nums1Size >= nums2Size)
  {
    max = nums1;
    min = nums2;
    len1 = nums1Size;
    len2 = nums2Size;
  }
  else
  {
    max = nums2;
    min = nums1;
    len1 = nums2Size;
    len2 = nums1Size;
  }
  int flag = 0, flag2 = 0;
  while((itr1 < len1 || itr2 < len2) && itr3 < lim && itr4 < tlen)
  {
    if(itr1 < len1 && itr2 < len2)
    {
      if(max[itr1] <= min[itr2])
      {
        medianArr[itr4] = max[itr1];
        //++itr4;
        //medianArr[itr4] = min[itr2];
        if(min[itr2] > max[itr1])
        {
          flag = 1;
        }
        else
        {
          ++itr4;
          medianArr[itr4] = min[itr2];
          flag = 0;
        }
      }
      else
      {
        medianArr[itr4] = min[itr2];
        //++itr4;
        //medianArr[itr4] = max[itr1];
        flag = 2;
      }
    }
    else if(itr2 >= len2 && itr1 < len1)
    {
      medianArr[itr4] = max[itr1];
      flag = 0;
    }
    else
    {
      if(flag == 1)
      {
        if(itr2 == len2)
        {
          medianArr[itr4] = min[itr2 -1];
        }
        else
        {
          medianArr[itr4] = min[itr2];
        }
      }
      else if(flag == 2)
      {
        if(itr1 == len1)
        {
          medianArr[itr4] = max[itr1 -1];
        }
        else
        {
          medianArr[itr4] = max[itr1];
        }
      }
    }
    ++itr1;
    ++itr2;
    ++itr3;
    ++itr4;
    if(flag == 1)
    {
      --itr2;
      //--itr4;
    }
    else if(flag == 2)
    {
      //--itr4;
      --itr1;
    }
    if(itr2 >= len2)
    {
      itr2 = len2;
      flag2 =1;
    }
  }
  double median;
  if(tlen%2 == 0)
  {
    median = ((double)(medianArr[lim-1]+medianArr[lim-2]))/2;
    free(medianArr);
    return median;
  }
  else
  {
    median = (double)medianArr[mid-1];
    free(medianArr);
    return median;
  }
}

void ip(int *arr,int len)
{
  for(int i = 0; i < len; i++)
  {
    scanf("%d",arr+i);
  }
}

int main(void)
{
  int *arr1;
  int *arr2;

  int len1;
  int len2;

  scanf("%d%d",&len1,&len2);
  arr1 = (int *)calloc(len1,sizeof(*arr1));
  arr2 = (int *)calloc(len2,sizeof(*arr2));
  ip(arr1,len1);
  ip(arr2,len2);
  double ret = findMedianSortedArrays(arr1,len1,arr2,len2);
  printf("%lf\n",ret);
  free(arr1);
  free(arr2);
  return EXIT_SUCCESS;
}
