#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static int reverse(int x)
{
  char str[12];
  snprintf(str,12,"%d",x);
  int len = strlen(str);
  char *rev = (char *)calloc(len+1,sizeof(char));

  int itr = len-1, itr1 = 0;
  if(x < 0)
  {
    itr1 = 1;
    itr = len-1;
    rev[0] = '-';
  }
  while(str[itr1] != '\0')
  {
    rev[itr] = str[itr1];
    itr--;
    itr1++;
  }
  rev[len] = '\0';
  long long int revInt;
  sscanf(rev,"%llu",&revInt);
  free(rev);
  if(revInt < INT_MIN || revInt > INT_MAX)
  {
    return 0;
  }
  return revInt;
}

int main(void)
{
  int x;
  scanf("%d",&x);
  while((getchar()) != '\n');
  int revX = reverse(x);
  printf("%d\n",revX);
  return EXIT_SUCCESS;
}
