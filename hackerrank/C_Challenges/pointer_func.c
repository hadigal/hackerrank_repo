#include <stdio.h>
#include <stdlib.h>

void update(int *, int *);

int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  int *pa,*pb;
  pa = &a;
  pb = &b;
  update(pa,pb);
  printf("%d\n%d\n",a,b);
  return 0;
}

void update(int *pa, int *pb)
{
  int temp1, temp2;
  temp1 = *pa + *pb;
  temp2 = abs((*pa - *pb));
  *pa = temp1;
  *pb = temp2;
}
