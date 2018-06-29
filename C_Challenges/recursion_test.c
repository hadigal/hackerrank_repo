#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int curr = 3;
void find_nth_term(int n, int a, int b, int c)
{
  int nthTerm;
  nthTerm = a + b + c;
  a = b;
  b = c;
  c = nthTerm;
  curr++;
  if(curr == n)
  {
    printf("%d\n", nthTerm);
  }
  else
  {
    find_nth_term(n,a,b,c);
  }
}

int main()
{
  int n, a, b, c;
  scanf("%d %d %d %d", &n, &a, &b, &c);
  find_nth_term(n, a, b, c);
  return 0;
}
