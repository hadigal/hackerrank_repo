#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10*10*10

void bit_op(int , int *, int, int);
int det_val(int , int , int );

int main()
{
  int n,k,*arr;
  setbuf(stdout,NULL);
  scanf("%d %d",&n,&k);

  if((n < 2) || (n > MAX) || (k < 2) || (k > n))
  {
    printf("Error in i/p\n");
    return -1;
  }
  arr = (int *)calloc(n,sizeof(int));
  int *res, limit=0, i, j;

  arr[0] = 1;
  for(i =1; i < n; i++)
  {
    arr[i] = *(arr + (i-1)) + 1;
  }

  //and
  bit_op(k,arr,n,1);
  //or
  bit_op(k,arr,n,2);
  //xor
  bit_op(k,arr,n,3);
  free(arr);
  return 0;
}

void bit_op(int max_val, int *arr, int n, int flag)
{
  int i,j;
  int print_val = 0, temp;
  for(i = 0; i < n; i++)
  {
    for(j = i + 1; j < n; j++)
    {
      if(flag == 1)
      {
        temp = arr[i] & *(arr + j);
        print_val = det_val(temp,print_val,max_val);
      }
      else if(flag == 2)
      {
        temp = arr[i] | *(arr + j);
        print_val = det_val(temp,print_val,max_val);
      }
      else if(flag == 3)
      {
        temp = arr[i] ^ *(arr + j);
        print_val = det_val(temp,print_val,max_val);
      }
    }
  }
  printf("%d\n",print_val);
}

int det_val(int temp, int print_val, int k)
{
  if((temp > print_val) && (temp < k))
  {
    print_val = temp;
  }
  return print_val;
}
