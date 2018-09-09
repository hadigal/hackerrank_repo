#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int num;
  scanf("%d",&num);
  int *birds;
  birds = (int *)calloc(num,sizeof(int));
  int *count = (int *)calloc(5,sizeof(int));
  //max = 0;
  for(int i = 0; i < num; i++)
  {
    scanf("%d",birds+i);
    // switch(birds[i])
    // {
    //   case 1:
    //     ++count[0];
    //   case 2:
    //     ++count[1];
    //   case 3:
    //     ++count[2];
    //   case 4:
    //     ++count[3];
    //   case 5:
    //     ++count[4];
    // }
    if(birds[i] == 1)
    {
      ++count[0];
    }
    else if(birds[i] == 2)
    {
      ++count[1];
    }
    else if(birds[i] == 3)
    {
      ++count[2];
    }
    else if(birds[i] == 4)
    {
      ++count[3];
    }
    else if(birds[i] == 5)
    {
      ++count[4];
    }
    else
    {
      printf("error in ip\n");
      return EXIT_FAILURE;
    }
  }

  if(count[0] >= count[1] &&  count[0] >= count[2] && count[0] >= count[3] && count[0] >= count[4])
  {
    printf("1\n");
    return EXIT_SUCCESS;
  }
  else if(count[1] > count[0] &&  count[1] >= count[2] && count[1] >= count[3] && count[1] >= count[4])
  {
    printf("2\n");
    return EXIT_SUCCESS;
  }
  else if(count[2] > count[0] &&  count[2] > count[1] && count[2] >= count[3] && count[2] >= count[4])
  {
    printf("3\n");
    return EXIT_SUCCESS;
  }
  else if(count[3] > count[0] &&  count[3] > count[1] && count[3] > count[2] && count[3] >= count[4])
  {
    printf("4\n");
    return EXIT_SUCCESS;
  }
  else
  {
    printf("5\n");
    return EXIT_SUCCESS;
  }
}
