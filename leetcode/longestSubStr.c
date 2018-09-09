#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *str)
{
  unsigned int len = strlen(str);
  if(len == 1)
  {
    return len;
  }
  int max = 0,count;
  int lim = -1;
  for(int itr = 1; itr < len; itr++)
  {
    count = 1;
    for(int itr1 = itr-1; itr1 >= 0 && itr1 > lim; itr1--)
    {
      if(str[itr] == str[itr1])
      {
        lim = itr1;
        break;
      }
      count++;
    }
    if(max < count)
    {
      max  = count;
    }
  }
  return max;
}

int main(void)
{
  char *str = (char *)calloc(256,sizeof(char));
  scanf("%[^\n]s",str);
  while((getchar()) != '\n');
  int len = lengthOfLongestSubstring(str);
  printf("%d\n",len);
  free(str);
  return EXIT_SUCCESS;
}
