#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int *arr[6],i,j;
  for(i = 0; i < 6; i++)
  {
    arr[i] = (int *)malloc(6*sizeof(int));
    if(!arr[i])
    {
      printf("ERROR: malloc() arr[%d][j]\n",i);
      exit(EXIT_FAILURE);
    }
  }
  for(i = 0; i < 6; i++)
  {
    for(j = 0; j < 6; j++)
    {
      scanf("%d",arr[i] + j);
      if(arr[i][j] < -9 || arr[i][j] > 9)
      {
        printf("error in i/p:\n");
        exit(EXIT_FAILURE);
      }
    }
  }
  int *hg_sum = (int *)calloc(16,sizeof(int));
  if(!hg_sum)
  {
    printf("ERROR: malloc() hg_sum\n");
    exit(EXIT_FAILURE);
  }
  // hourglass calucation
  int count = 0;
  for(i = 0; i < 4; i++)
  {
    for(j = 0; j < 4; j++)
    {
      if(count > 15)
      {
        printf("ERROR in count var:%d",count);
        exit(EXIT_FAILURE);
      }
      hg_sum[count] = arr[i][j] + arr[i][j+1] + arr[i][j+2];
      hg_sum[count] += arr[i+1][j+1];
      hg_sum[count] += arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
      count++;
    }
  }
  int max = hg_sum[0];
  for(i = 0; i < count; i++)
  {
    if(hg_sum[i] > max)
    {
      max = hg_sum[i];
    }
  }
  printf("%d\n",max);
  free(hg_sum);
  for(i = 0; i < 6; i++)
  {
    free(arr[i]);
  }
  return 0;
}
