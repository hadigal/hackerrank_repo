#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;

int main(void)
{
  char *steps;
  u32 count;
  scanf("%u",&count);
  steps = (char *)calloc(count,sizeof(char));
  int dCount = 0,uCount = 0, vCount = 0, cD = 1, cU = 1;
  int seaLevel = 0, flag =0;
  /*
  * Clearing the stdin BUFF containing trainling new line after scanf() i/p
  * very effecting method and saving the rest of the input using get char method
  * char is treated as int by the compiler
  */
  while((getchar()) != '\n');
  for(int itr = 0; itr < count; itr++)
  {
    steps[itr] = getchar();
    if(steps[itr] == 'D')
    {
      if(seaLevel == 0)
      {
        flag = 1;
      }
      ++dCount;
      --seaLevel;
      if(itr > 0 && steps[itr-1] == 'D')
      {
        cD++;
      }
    }
    else
    {
      ++uCount;
      ++seaLevel;
      if(itr > 0 && steps[itr-1] == 'U')
      {
        cU++;
      }
    }
    if((cD > cU && uCount == dCount && seaLevel == 0) ||
    (flag == 1 && cD == cU && seaLevel == 0 && uCount > 0 && dCount > 0))
    {
      vCount++;
      cD = 1;
      cU = 1;
      uCount = 0;
      dCount = 0;
      if(flag == 1)
      {
        flag = 0;
      }
    }
  }
  printf("%d\n",vCount);
  free(steps);
  return EXIT_SUCCESS;
}
