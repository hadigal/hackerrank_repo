#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int num;
  scanf("%d",&num);
  int *arr = (int *)calloc(num,sizeof(int));
  int minCount = 0, maxCount = 0;
  int max, min;
  for(int i = 0; i < num; i++)
  {
    scanf("%d",arr+i);
    if(i == 0)
    {
      min = arr[i];
      max = arr[i];
    }
    else
    {
      if(arr[i] < min)
      {
        min = arr[i];
        ++minCount;
      }
      else if(arr[i] > max)
      {
        max = arr[i];
        maxCount++;
      }
      else
      {
        continue;
      }
    }
  }
  printf("%d %d\n",maxCount,minCount);
  free(arr);
  return EXIT_SUCCESS;
}
