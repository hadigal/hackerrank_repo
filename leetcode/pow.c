#include <stdio.h>

int powOf(int num,int pow)
{
  int i = pow, res = num;
  if(pow == 1)
  {
    return num;
  }
  else if(pow == 0)
  {
    return 1;
  }

  while(i >= 2)
  {
    res = res * num;
    i--;
  }
  return res;
}

int main(void)
{
  int pow,num;
  scanf("%d%d",&num,&pow);
  int res = powOf(num,pow);
  printf("res(%d^%d):%d\n",num,pow,res);
  return 0;
}
