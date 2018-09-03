#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;

int main(void)
{
  u32 *bill;
  u32 num, index;
  scanf("%u%u",&num,&index);
  bill = (u32 *)calloc(num,sizeof(u32));
  u32 bAct = 0;
  for(int itr = 0; itr < num; itr++)
  {
    scanf("%u",bill+itr);
    bAct += bill[itr];
  }
  u32 bSh = bAct - bill[index];
  u32 amtCh;
  scanf("%u",&amtCh);
  u32 actCh = (u32)(bSh/2);
  if(amtCh == actCh)
  {
    printf("Bon Appetit\n");
    free(bill);
    return EXIT_SUCCESS;
  }
  else
  {
    printf("%u\n",amtCh-actCh);
    free(bill);
    return EXIT_SUCCESS;
  }
}
