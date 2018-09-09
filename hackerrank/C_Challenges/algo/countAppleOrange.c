#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int input(int *arr, int num,const int *house,int dis)
{
  int val,count = 0;
  for(int itr = 0; itr < num; itr++)
  {
    val = dis;
    scanf("%d",&arr[itr]);
    val += arr[itr];
    if(val >= house[0] && val <= house[1])
    {
      count++;
    }
  }
  return count;
}

int main(void)
{
  int house[2];
  scanf("%d%d",&house[0],&house[1]);
  int ap,or;
  scanf("%d%d",&ap,&or);
  int ap_num, or_num;
  scanf("%d%d",&ap_num,&or_num);
  int *apArr = (int *)calloc(ap_num,sizeof(int));
  int *orArr = (int *)calloc(or_num,sizeof(int));
  int ap_count,or_count;

  ap_count = input(apArr,ap_num,house,ap);
  or_count = input(orArr,or_num,house,or);

  printf("%d\n%d\n",ap_count,or_count);
  free(apArr);
  free(orArr);

  return EXIT_SUCCESS;
}
