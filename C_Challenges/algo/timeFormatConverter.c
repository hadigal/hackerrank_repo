#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  unsigned int h,m,s;
  char *fmt = (char *)calloc(2,sizeof(char));

  scanf("%d%*1[:]%d%*1[:]%d%s",&h,&m,&s,fmt);
  char *milFmt = (char *)calloc(9,sizeof(char));
  if(strcmp(fmt,"AM") == 0)
  {
    if(h == 12)
    {
      h = 0;
    }
    //snprintf(milFmt,9,"%d:%d:%d",)
    printf("%02d:%02d:%02d\n",h,m,s);
    return EXIT_SUCCESS;
  }
  else if(strcmp(fmt,"PM") == 0)
  {
    if(h == 12)
    {
      h = h;
    }
    else
    {
      h += 12;
    }
    printf("%02d:%02d:%02d\n",h,m,s);
    return EXIT_SUCCESS;
  }
  else
  {
    printf("Error in i/p\n");
    return EXIT_FAILURE;
  }
}
