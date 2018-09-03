#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  short int *arr;
  short int num;
  scanf("%hd",&num);
  if(num < 0 || num > 100)
  {
    return EXIT_FAILURE;
  }
  arr = (short int *)calloc(num,sizeof(short int));
  int pcount = 0, ncount = 0, zcount = 0;
  for(int itr = 0; itr < num; itr++)
  {
    scanf("%hd",&arr[itr]);
    if(arr[itr] < -100 || arr[itr] > 100)
    {
      return EXIT_FAILURE;
    }
    if(arr[itr] > 0)
    {
      pcount++;
    }
    else if(arr[itr] < 0)
    {
      ncount++;
    }
    else
    {
      zcount++;
    }
  }
  printf("%.6f\n",(float)((float)pcount/(float)num));
  printf("%.6f\n",(float)((float)ncount/(float)num));
  printf("%.6f\n",(float)((float)zcount/(float)num));
  free(arr);
  return EXIT_SUCCESS;
}
