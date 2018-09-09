#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *str;
  str = (char *)malloc(1000*sizeof(char));
  scanf("%s",str);
  if(!str)
  {
    exit(EXIT_FAILURE);
  }
  int len = strlen(str);
  //printf("len:%d\n",len);
  if(realloc(str,len + 1) == NULL)
  {
    exit(EXIT_FAILURE);
  }
  int i,j, count;
  for(i = 0; i <= 9; i++)
  {
    count = 0;
    for(j = 0; j <= len; j++)
    {
      if(str[j] > 47 && str[j] < 58)
      {
        //printf("%d\n",(str[j] - '0'));
        if((str[j] - '0') == i)
        {
          count++;
        }
      }
    }
    if(i == 9)
    {
      printf("%d\n",count);
    }
    else
    {
      printf("%d ",count);
    }
  }
  free(str);
  return 0;
}
