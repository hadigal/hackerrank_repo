/*******************************************************************************
* File: var_arr.c
* Author: Hrihsikesh Adigal
* Email: hadigal@sdsu.edu
* Date: 06/08/2018
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define N_MAX 10*10*10*10*10
#define MAX_VAL N_MAX*10

void free_mem(int **,int *,int , int );

int main()
{
  int **a,n,q;
  int *k,i,j,l1,l2;
  setbuf(stdout, NULL);
  printf("\nEnter n and q:\n");
  scanf("%d %d",&n,&q);
  if((n < 1) || (n > N_MAX) || (q < 1) || (q > N_MAX))
  {
    printf("\nERROR INVLAID VAL. OF n or q\n");
    return -1;
  }
  a = calloc(n,sizeof(int *));
  k = (int *)calloc(n,sizeof(int));
  int temp;
  for(l1 = 0; l1 < n; l1++)
  {
    printf("\nEnter k and *(a[i]+j):\n");
    scanf("%d",k+l1);
    if((k[l1] < 1) || (k[l1] > MAX_VAL))
    {
      printf("\nERROR INVLAID VAL. OF K\n");
      free_mem(a,k,0,n);
      return -1;
    }
    a[l1] = (int *)calloc(k[l1],sizeof(int));
    for(l2 = 0; l2 < k[l1]; l2++)
    {
      scanf("%d",a[l1]+l2);
      if((*(a[l1]+l2) < 1) || (*(a[l1]+l2) > MAX_VAL))
      {
        printf("\nERROR INVLAID VAL. OF *(a[i]+j)\n");
        free_mem(a,k,1,n);
        return -1;
      }
    }
  }
  printf("\nNow enter [%d] i and j pairs for getting value at *(a[i] +j) memory locations\n",n);
  for(l1 = 0; l1 < q; l1++)
  {
    scanf("%d %d",&i,&j);
    if((i < 0) || (i > n))
    {
      printf("\nERROR INVLAID VAL. OF i\n");
      free_mem(a,k,1,n);
      return -1;
    }
    else if((j < 0) || (j >= k[i]))
    {
      printf("\nERROR INVLAID VAL. OF j\n");
      free_mem(a,k,1,n);
      return -1;
    }
    printf("\n********* Output *********\n");
    printf("%d\n",*(a[i]+j));
    printf("\n**************************\n");
  }
  free_mem(a,k,1,n);
  return 0;
}

void free_mem(int **a,int *k,int flag,int n)
{
  int i;
  if(flag == 1)
  {
    for(i = 0; i < n; i++)
    {
      free(a[i]);
    }
  }
  free(a);
  free(k);
}
