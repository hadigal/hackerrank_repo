#include <stdio.h>

int main()
{
  int i,j,k, n,p;
  scanf("%d",&n);
  if((n < 1) || (n > 1000))
  {
    printf("Invalid i/p; Correct format: 1 <= n <=1000\n");
    return -1;
  }
  //printf("\n****************** OUTPUT ******************\n");
  for(i = 1; i<=n; i++)
  {
    p = n;
    for(j = 1; j <= i - 1; j++)
    {
      printf("%d ",p--);
    }
    for(j = 1; j <= 2*(n-i) + 1; j++)
    {
      printf("%d ",n+1-i);
    }
    p = n-i+2;
    for(j = 1; j<= i - 1; j++)
    {
      printf("%d ",p++);
    }
    printf("\n");
  }
  for(i = 1; i<=n - 1; i++)
  {
    p = n;
    for(j = 1; j <= n -1 - i ; j++)
    {
      printf("%d ",p--);
    }
    for(j = 1; j <= 2*(i+1) - 1; j++)
    {
      printf("%d ",i+1);
    }
    p = p + 1;
    for(j = 1; j<= n -1 - i; j++)
    {
      printf("%d ",p++);
    }
    printf("\n");
  }
  return 0;
}
