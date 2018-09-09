#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int num,k;
  scanf("%d%d",&num,&k);
  int *arr;
  arr = (int *)calloc(num,sizeof(int));
  for(int i = 0; i < num; i++)
  {
    scanf("%d",arr+i);
  }
  int count = 0;
  int temp;
  for(int i = 0; i < num - 1; i++)
  {
    for(int j = i+1; j < num; j++)
    {
      temp = arr[i] + arr[j];
      if(temp%k == 0)
      {
        count++;
      }
    }
  }
  printf("%d\n",count);
  free(arr);
  return EXIT_SUCCESS;
}
