#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *res;
char* catAndMouse(int c1, int c2, int m)
{
  int d1, d2;
  d1 = m - c1;
  if(d1 < 0)
  {
    d1 *= -1;
  }
  d2 = m - c2;
  if(d2 < 0)
  {
    d2 *= -1;
  }
  if(d1 == d2)
  {
    res = (char *)calloc(8,sizeof(*res));
    sprintf(res,"Mouse C");
    return res;
  }
  else
  {
    res = (char *)calloc(6,sizeof(*res));
    if(d1 < d2)
    {
      sprintf(res,"Cat A");
      return res;
    }
    else
    {
      sprintf(res,"Cat B");
      return res;
    }
  }
}

int main(void)
{
  int tc_num;
  scanf("%d",&tc_num);
  int **tc = (int **)calloc(tc_num,sizeof(*tc));
  char *str;
  for(int itr = 0; itr < tc_num; ++itr)
  {
    tc[itr] = (int *)calloc(3,sizeof(*tc[itr]));
    scanf("%d%d%d",tc[itr]+0,tc[itr]+1,tc[itr]+2);
    str = catAndMouse(tc[itr][0],tc[itr][1],tc[itr][2]);
    printf("%s\n",str);
    free(tc[itr]);
    free(str);
  }
  free(tc);
  return EXIT_SUCCESS;
}
