#include <stdio.h>

int main()
{
  int i,j,n=5;
  for(i = 1; i <= n; i++)
  {
    for(j = n; j > i; j--)
    {
      printf(" ");
    }
    for(j = 1; j <= i; j++)
    {
      printf("* ");
      /*To print as below:
             *
            * *
           * * *
          * * * *
         * * * * *
      */

      //printf("%d ",j);
      /*To print as below:
             1
            1 2
           1 2 3
          1 2 3 4
         1 2 3 4 5
      */

      //printf("%d ",i);
      /* To print as below:
             1
            2 2
           3 3 3
          4 4 4 4
         5 5 5 5 5
      */
    }
    printf("\n");
  }
  return 0;
}
