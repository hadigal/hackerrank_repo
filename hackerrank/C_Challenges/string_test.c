#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char *sen,ch,*s;
  sen = (char *)malloc(100*sizeof(char));
  s = (char *)malloc(25*sizeof(char));
  setbuf(stdout,NULL);
  scanf("%c",&ch);
  scanf("%s\n",s);
  // make sure the \n is added before the next scanf; as the format specifer in
  // the next scanf i.e. below will take the \n from the previous scanf i/p as the
  // escape char for \n mentioned in it's format specifer
  scanf("%[^\n]%*c",sen);
  printf("%c\n",ch);
  printf("%s\n",s);
  printf("%s\n",sen);
  free(s);
  free(sen);
  return 0;
}
