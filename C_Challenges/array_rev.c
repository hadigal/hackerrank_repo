#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000


void print_arr(int *arr, int len)
{
  int i;
  for(i = 0; i < len; i++)
  {
    if(i == len -1)
    {
      printf("%d",arr[i]);
    }
    else
    {
      printf("%d ",arr[i]);
    }
  }
  printf("\n");
}

int main()
{
  int n,*arr,*rev_arr, i, temp;
  scanf("%d",&n);
  if((n < 1) || (n > MAX))
  {
    printf("Error in array length i/p\n");
    return -1;
  }
  arr = (int *)calloc(n,sizeof(int));
  rev_arr = (int *)calloc(n,sizeof(int));
  temp = n - 1;
  for(i = 0; i < n; i++)
  {
    scanf("%d",arr + i);
    if((arr[i] < 1) || (arr[i] > MAX))
    {
      printf("error in element i/p\n");
      return -1;
    }
    rev_arr[temp] = arr[i];
    temp--;
  }
  print_arr(rev_arr,n);
  free(arr);
  free(rev_arr);
  return 0;
}
