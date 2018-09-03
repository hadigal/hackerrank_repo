#include <stdio.h>
#include <stdlib.h>

void arrIp(int *arr, int len)
{
  for(int itr = 0; itr < len; itr++)
  {
    scanf("%d",arr+itr);
  }
}

int main(void)
{
  int num;
  scanf("%d",&num);
  int *sock = (int *)calloc(num,sizeof(int));
  arrIp(sock,num);

  int p1 = 0, itr =0, *p2, pCount = 0;
  p2 = (int *)calloc(1,sizeof(int));
  int ct = 1;
  while(itr < num)
  {
    p1 = itr;
    for(int itr2 = itr+1; itr2 < num; itr2++)
    {
      if(p2[ct-1] == itr2)
      {
        continue;
      }
      else if(sock[itr2] == sock[p1])
      {
        pCount++;
        p2[ct-1] = itr2;
        p2 = realloc(p2,(ct+1)*sizeof(int));
        ct++;
        break;
      }
    }
    itr++;
    int itr2 = 0;
    while(itr2 < ct)
    {
      if(itr == p2[itr2])
      {
        ++itr;
        itr2 = 0;
        continue;
      }
      itr2++;
    }
  }
  printf("%d\n",pCount);
  free(sock);
  free(p2);
  return EXIT_SUCCESS;
}
