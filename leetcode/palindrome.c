#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static bool isPalindrome(int x)
{
  if(x < 0)
  {
    return false;
  }
  char str[12];
  snprintf(str,12,"%d",x);
  unsigned int len = strlen(str);
  char *rev = (char *)calloc(len+1,sizeof(*rev));
  int itr1 = 0, itr2 = len-1;
  while(str[itr1] != '\0')
  {
    rev[itr2] = str[itr1];
    if(rev[itr2] != str[itr2])
    {
      free(rev);
      return false;
    }
    ++itr1;
    --itr2;
  }
  rev[len] = '\0';
  int res;
  sscanf(rev,"%d",&res);
  free(rev);
  // if(res == x)
  // {
  //   return true;
  // }
  // else
  // {
  //   return false;
  // }
  return (x == res) ? true : false;
}

int main(void)
{
  int x;
  scanf("%d",&x);
  bool res = isPalindrome(x);
  fputs(res ? "true\n":"false\n",stdout);
  return EXIT_SUCCESS;
}
