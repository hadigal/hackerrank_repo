#include <stdio.h>

int main()
{
  int i,j,n=5;
  // upper triangle
  for(i = 1; i <= n; i++)
  {
    for(j = n; j > i; j--)
    {
      printf(" ");
    }
    for(j = 1; j <= 2*i-1; j++)
    {
      printf("*");
    }
    printf("\n");
  }
  // below triangle
  for(i = 1; i <= n - 1; i++)
  {
    for(j = 1; j <= i; j++)
    {
      printf(" ");
    }
    for(j = 2*(n-1) - i; j >= i ; j--)
    {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
