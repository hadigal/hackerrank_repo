#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int num;
  scanf("%d",&num);
  if(num < 0 || num > 1000)
  {
    return EXIT_FAILURE;
  }
  int *arr = (int *)calloc(num,sizeof(int));
  int sum = 0;
  for(int itr = 0; itr < num;itr++)
  {
    scanf("%d",arr+itr);
    if(arr[itr] < 0 || arr[itr] > 1000)
    {
      return EXIT_FAILURE;
    }
    sum += arr[itr];
  }
  printf("%d\n",sum);
  free(arr);
  return EXIT_SUCCESS;
}
