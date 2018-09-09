#include <stdio.h>
#include <stdlib.h>



static int *compare(unsigned int **arr, unsigned int *op)
{
  for(int itr = 0; itr < 3; itr++)
  {
    if(arr[0][itr] > arr[1][itr])
    {
      ++op[0];
    }
    else if(arr[0][itr] < arr[1][itr])
    {
      ++op[1];
    }
    else
    {
      op[0] += 0;
      op[1] += 0;
    }
  }
  return op;
}

int main(void)
{
  unsigned int **trpArr = (unsigned int **)calloc(2,sizeof(unsigned int *));
  trpArr[0] = (unsigned int *)calloc(3,sizeof(unsigned int));
  trpArr[1] = (unsigned int *)calloc(3,sizeof(unsigned int));
  unsigned int *op = (unsigned int *)calloc(2,sizeof(unsigned int));
  op[0] = 0;
  op[1] = 0;

  scanf("%u%u%u",&trpArr[0][0],&trpArr[0][1],&trpArr[0][2]);
  if(trpArr[0][0] > 100 || trpArr[0][1] > 100 || trpArr[0][3] > 100)
  {
    return EXIT_FAILURE;
  }
  scanf("%u%u%u",&trpArr[1][0],&trpArr[1][1],&trpArr[1][2]);
  if(trpArr[1][0] > 100 || trpArr[1][1] > 100 || trpArr[1][3] > 100)
  {
    return EXIT_FAILURE;
  }

  op = compare(trpArr,op);
  printf("%d %d\n",op[0],op[1]);
  free(trpArr[0]);
  free(trpArr[1]);
  free(trpArr);
  free(op);
  return EXIT_SUCCESS;
}
