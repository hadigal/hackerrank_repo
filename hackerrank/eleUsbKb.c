#include <stdio.h>
#include <stdlib.h>

void ip(int *arr, int len)
{
  for(int itr= 0; itr < len;++itr)
  {
    scanf("%d",arr+itr);
  }
}

int getMoneySpent(int tKb, int *kb, int tUsb, int *usb, int bud)
{
  int itr1 = 0, itr2;
  int max = 0, temp,temp2;
  while(itr1 < tKb)
  {
    temp = 0;
    if(kb[itr1] >= bud)
    {
      ++itr1;
      continue;
    }
    temp += kb[itr1];
    itr2 = 0;
    while(itr2 < tUsb)
    {
      // temp2 = 0;
      temp2 = temp + usb[itr2];
      if(temp2 > bud)
      {
        ++itr2;
        continue;
      }
      else if(temp2 > max && temp2 <= bud)
      {
        max = temp2;
      }
      ++itr2;
    }
    ++itr1;
  }
  if(max == 0)
  {
    return -1;
  }
  else
  {
    return max;
  }
}

int main(void)
{
  int bud,tUsb,tKb;
  scanf("%d%d%d",&bud,&tKb,&tUsb);
  int *kb = (int *)calloc(tKb,sizeof(*kb));
  int *usb = (int *)calloc(tUsb,sizeof(*usb));
  ip(kb,tKb);
  ip(usb,tUsb);
  int ret = getMoneySpent(tKb,kb,tUsb,usb,bud);
  printf("%d\n",ret);
  free(kb);
  free(usb);
  return EXIT_SUCCESS;
}
