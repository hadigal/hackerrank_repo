#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int x1,v1,x2,v2;
  int temp1, temp2;
  scanf("%d%d%d%d",&x1,&v1,&x2,&v2);
  if((v1 < v2 && x1 < x2) || (v2 < v1 && x2 < x1))
  {
    printf("NO\n");
    return EXIT_SUCCESS;
  }
  else if(v1 < v2 && x1 > x2)
  {
    temp1 = x1;
    temp2 = x2;
    int diff = temp1 - temp2,diff2;
    while(temp1 > temp2)
    {
      temp1 += v1;
      temp2 += v2;
      if(temp1 == temp2)
      {
        printf("YES\n");
        return EXIT_SUCCESS;
      }
      diff2 = temp2 - temp1;
      if(diff2 >= diff)
      {
        break;
      }
    }
    printf("NO\n");
    return  EXIT_SUCCESS;
  }
  else if(x1 < x2 && v1 > v2)
  {
    temp1 = x1;
    temp2 = x2;
    int diff =  temp2 -  temp1, diff2;
    while(temp1 < temp2)
    {
      temp1 += v1;
      temp2 += v2;
      if(temp1 == temp2)
      {
        printf("YES\n");
        return EXIT_SUCCESS;
      }
      diff2 = temp1 - temp2;
      if(diff2 >= diff)
      {
        break;
      }
    }
    printf("NO\n");
    return  EXIT_SUCCESS;
  }
  else if (x1 == x2 && v1 == v2)
  {
    printf("YES\n");
    return EXIT_SUCCESS;
  }
  else if((x1 == x2 && v1 > v2) || (x1 == x2 && v1 < v2) || (v1 == v2))
  {
    printf("NO\n");
    return EXIT_SUCCESS;
  }
}
