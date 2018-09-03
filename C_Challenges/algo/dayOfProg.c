#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int year;
  scanf("%d",&year);
  if(year > 1918)
  {
    if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
    {
      printf("12.09.%d\n",year);
      return EXIT_SUCCESS;
    }
    else
    {
      printf("13.09.%d\n",year);
      return EXIT_SUCCESS;
    }
  }
  else if(year >= 1700 && year < 1918)
  {
    if(year%4 == 0)
    {
      printf("12.09.%d\n",year);
      return EXIT_SUCCESS;
    }
    else
    {
      printf("13.09.%d\n",year);
      return EXIT_SUCCESS;
    }
  }
  else if(year == 1918)
  {
    printf("26.09.%d\n",year);
    return EXIT_SUCCESS;
  }
  else
  {
    printf("Erro in i/p\n");
    return EXIT_FAILURE;
  }
}
