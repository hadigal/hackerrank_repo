#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int len,pg;
  scanf("%d%d",&len,&pg);
  if(len == pg || pg == 1)
  {
    printf("0\n");
    return EXIT_SUCCESS;
  }

  int mid = len/2,pgCount = 0;

  if(pg <= mid)
  {
    int itr = 1;
    while(itr <= pg)
    {
      if(itr > 1)
      {
        pgCount++;
      }
      itr += 2;
      if(pg == itr-1)
      {
        pgCount++;
        break;
      }
    }
    printf("%d\n",pgCount);
    return EXIT_SUCCESS;
  }
  else
  {
    int itr = len;
    while(itr >= pg)
    {
      if(itr < len)
      {
        pgCount++;
      }
      itr -= 2;
      if((len%2 == 0 && pg == itr+1) || (len%2 != 0 && pg == itr-1))
      {
        pgCount++;
        break;
      }
    }
    printf("%d\n",pgCount);
    return EXIT_SUCCESS;
  }
}
