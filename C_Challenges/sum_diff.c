#include <stdio.h>
#include <stdlib.h>

#define MAX 10*10*10*10

int main()
{
  int i1,i2;
  float f1,f2;
  setbuf(stdout,NULL);
  scanf("%d %d %f %f",&i1,&i2,&f1,&f2);
  if((i1 < 1) || (i1 > MAX) || (i2 < 1) || (i2 > MAX) || (f1 < 1) || (f1 > (float)MAX) || (f2 < 1) || (f2 > (float)MAX))
  {
    return -1;
  }
  printf("%d %d\n",(i1+i2),(i1 - i2));
  printf("%.1f %.1f\n",(f1+f2),(f1 - f2));
  return 0;
}
