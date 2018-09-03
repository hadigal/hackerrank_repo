#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int num;
  scanf("%d",&num);
  int *arr;
  arr = (int *)calloc(num,sizeof(int));
  for(int i = 0; i < num; i++)
  {
    scanf("%d",arr+i);
  }
  int day, mon,temp, count = 0;
  scanf("%d%d",&day,&mon);
  for(int i = 0; i < num - (mon -1); i++)
  {
    temp = arr[i];
    for(int j = i +1; j < i+mon && num; j++)
    {
      temp += arr[j];
    }
    if(temp == day)
    {
      count++;
    }
  }
  printf("%d\n",count);
  free(arr);
  return EXIT_SUCCESS;
}
