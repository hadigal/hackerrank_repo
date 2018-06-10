#include <stdio.h>
#include <stdlib.h>
#define MAX 10*10*10*10*10*10

int print_val(int);
void odd_even(int);

int main()
{
  int a,b, i, ret;
  setbuf(stdout,NULL);
  scanf("%d %d",&a,&b);
  if((a > MAX) || (b > MAX))
  {
    printf("Error:[a|b] > 10 ^6\n");
    return -1;
  }
  for(i = a; i <= b; i++)
  {
    ret = print_val(i);
    if(ret < 0)
    {
      printf("Error in i/p; i/p must be greater than 1");
      return -1;
    }
  }
  return 0;
}

int print_val(int n)
{
  if (n > 9)
  {
    odd_even(n);
  }
  else if (n == 1)
  {
    printf("one\n");
  }
  else if (n == 2)
  {
    printf("two\n");
  }
  else if (n == 3)
  {
    printf("three\n");
  }
  else if (n == 4)
  {
    printf("four\n");
  }
  else if (n == 5)
  {
    printf("five\n");
  }
  else if (n == 6)
  {
    printf("six\n");
  }
  else if (n == 7)
  {
    printf("seven\n");
  }
  else if (n == 8)
  {
    printf("eight\n");
  }
  else if (n == 9)
  {
    printf("nine\n");
  }
  else
  {
    printf("Wrong i/p; i/p < 1.\n");
    return -1;
  }
  return 0;
}

void odd_even(int val)
{
  if((val % 2) == 0)
  {
    printf("even\n");
  }
  else
  {
    printf("odd\n");
  }
}
