#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int n,ld = 0,fd;
  setbuf(stdout,NULL);
  scanf("%d",&n);
  if((n < 10000) || (n > 99999))
  {
    printf("Invalid i/p\n");
    return -1;
  }
  fd = n;
  while(1)
  {
    ld += fd % 10;
    fd = fd / 10;
    if(fd == 0)
    {
      break;
    }
  }
  printf("%d\n",ld);
  return 0;
}
