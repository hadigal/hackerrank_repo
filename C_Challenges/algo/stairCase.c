#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int num;
  scanf("%d",&num);
  if(num < 0 || num > 100)
  {
    return EXIT_FAILURE;
  }
  for(int itr = 1; itr <= num; itr++)
  {
    for(int itr1 = 1; itr1 <= num - itr; itr1++)
    {
      printf(" ");
    }
    for(int itr2 = 1; itr2 <= itr; itr2++)
    {
      printf("#");
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}
