#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char *c;
  c = (char *)malloc(100*sizeof(char));
  if(c == NULL)
  {
    return -1;
  }
  scanf("%[^\n]%s",c);
  printf("Hello, World!\n%s\n",c);
  free(c);
  return 0;
}
