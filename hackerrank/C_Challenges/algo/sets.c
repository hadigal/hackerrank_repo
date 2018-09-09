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
  int *arr1, *arr2;
  int num1,num2;
  scanf("%d%d",&num1,&num2);
  arr1 = (int *)calloc(num1,sizeof(int));
  arr2 = (int *)calloc(num2,sizeof(int));
  arrIp(arr1,num1);
  arrIp(arr2,num2);
  int temp = 0, mul, count = 0, flag2;
  mul = 1;

  while(temp < arr2[0])
  {
    label:
      temp = arr1[num1-1]*mul;
      if(temp > arr2[0])
      {
        break;
      }
      int flag = 0;
      for(int itr1 = 0; itr1 < num1; itr1++)
      {
        if(temp%arr1[itr1] != 0)
        {
          flag = 1;
          break;
        }
      }
      if(flag == 1)
      {
        mul++;
        goto label;
      }
      else
      {
        goto label2;
      }

    label2:
      flag2 = 0;
      for(int itr2 = 0; itr2 < num2; itr2++)
      {
        if(arr2[itr2]%temp != 0)
        {
          flag2 = 1;
          break;
        }
      }
      if(flag2 == 1)
      {
        mul++;
        goto label;
        //continue;
      }
      else
      {
        count++;
      }
      mul++;
  }
  
  printf("%d\n",count);
  free(arr1);
  free(arr2);
  return EXIT_SUCCESS;
}
