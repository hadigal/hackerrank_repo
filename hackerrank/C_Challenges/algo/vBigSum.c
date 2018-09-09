#include <stdio.h>
#include <stdlib.h>
#define MAX 10000000000

typedef long long unsigned int lluint;

int main(void)
{
  lluint *arr;
  lluint sum = 0;

  int num;
  scanf("%d",&num);
  arr = (lluint *)calloc(num,sizeof(lluint));

  for(int itr = 0;itr < num; itr++)
  {
    scanf("%llu",&arr[itr]);
    if(arr[itr] > MAX)
    {
      printf("error in i/p\n");
      return EXIT_FAILURE;
    }
    sum += arr[itr];
  }
  printf("%llu\n",sum);
  free(arr);
  return EXIT_SUCCESS;
}
