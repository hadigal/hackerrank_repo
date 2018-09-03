#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  short int **arr;
  int num;
  scanf("%d",&num);
  arr = (short int **)calloc(num,sizeof(short int *));
  int rt = 0, lf = 0;
  int rtItr = num - 1;
  int lfItr = 0;
  for(int itr = 0; itr < num; itr++)
  {
    arr[itr] = (short int *)calloc(num,sizeof(short int));
    for(int itr2 = 0; itr2 < num; itr2++)
    {
      scanf("%hd",&arr[itr][itr2]);
    }
    if(lfItr > num -1 || rtItr < 0)
    {
      printf("Error in logic\n");
      return EXIT_FAILURE;
    }
    lf += arr[itr][lfItr];
    rt += arr[itr][rtItr];
    lfItr++;
    rtItr--;
    free(arr[itr]);
  }
  int digDiff = rt - lf;
  if(digDiff < 0)
  {
    digDiff *= -1;
  }
  printf("%d\n",digDiff);
  free(arr);
  return EXIT_SUCCESS;
}
