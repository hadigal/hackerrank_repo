#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000

int main()
{
  int * arr, i, n, sum = 0;
  scanf("%d",&n);
  if((n < 1) || (n > MAX))
  {
    printf("\nError in i/p for # of array elements; correct: 1 <= n <= 1000\n");
    return -1;
  }
  arr = (int *)calloc(n,sizeof(int));
  for(i = 0; i < n; i++)
  {
    scanf("%d",arr + i);
    if((arr[i] < 1) || (arr[i] > MAX))
    {
      printf("\nError in i/p for arr[%d]; correct: 1 <= a[i] <= 1000\n",i);
      return -1;
    }
    sum += arr[i];
  }
  printf("%d\n",sum);
  free(arr);
  return 0;
}
