/*******************************************************************************
* File: var_sized_array.c
* Author: Hrihsikesh Adigal
* Email: hadigal@sdsu.edu
* Date: 06/08/2018
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define N_Q_LIMIT 10*10*10*10*10
#define K_LIMIT 3*(N_Q_LIMIT)

int *enter_arr_val(int *,int);

int main()
{

  int **a, k, n, q, i, j, *a2,loop;
  setbuf(stdout,NULL);
  printf("\nEnter the number of elements of array a and queries # q:\n");
  scanf("%d %d",&n,&q);
  //printf("\n%d %d\n",n,q);
  if((n < 1) || (n > N_Q_LIMIT) || (q < 1) || (q > N_Q_LIMIT))
  {
    printf("input error in array size n and query q\n");
    return -1;
  }
  a = calloc(n,sizeof(int *));
  //int *flag;
  for(loop = 0; loop < n; loop++)
  {
    //*flag = ;
    a[loop] = enter_arr_val(a[loop], k);
    if(*(a[loop]+0) == -1)
    {
      return -2;
    }
    //a[i] = a2;
  }
  for(loop = 0; loop < q; loop++)
  {
    printf("\nEnter array # i and its index to be queried j:\n");
    scanf("%d %d",&i,&j);
    if((i < 0) || (i >= n) || (j < 0) || (j > K_LIMIT))
    {
      return -2;
    }
    printf("\n********** Output **********\n");
    printf("%d\n",*(a[i]+j));
  }
  return 0;
}

int *enter_arr_val(int *arr,int size)
{
  int i,k;
  scanf("%d",&k);
  if((k < 1) || (k > K_LIMIT))
  {
    arr[0] = -1;
    return arr;
  }
  arr = (int *)calloc(k,sizeof(int));
  for(i = 0; i < k;i++)
  {
    scanf("%d", arr+i);
    if((*(arr+i) < 1) || (*(arr+i) < K_LIMIT))
    {
      arr[0] = -1;
      return arr;
    }
  }
  return arr;
}
