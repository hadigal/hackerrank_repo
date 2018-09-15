#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int romanToInt(char *str)
{
  int num = 0;
  int itr = 0;
  while(str[itr] != '\0')
  {
    if(str[itr] == 'I')
    {
      ++itr;
      if(str[itr] != '\0')
      {
        if(str[itr] == 'V')
        {
          num += 4;
        }
        else if(str[itr] == 'X')
        {
          num += 9;
        }
        else
        {
          --itr;
          num += 1;
        }
      }
      else
      {
        num += 1;
        break;
      }
    }
    else if(str[itr] == 'X')
    {
      ++itr;
      if(str[itr] != '\0')
      {
        if(str[itr] == 'L')
        {
          num += 40;
        }
        else if(str[itr] == 'C')
        {
          num += 90;
        }
        else
        {
          --itr;
          num += 10;
        }
      }
      else
      {
        num += 10;
        break;
      }
    }
    else if(str[itr] == 'C')
    {
      ++itr;
      if(str[itr] != '\0')
      {
        if(str[itr] == 'D')
        {
          num += 400;
        }
        else if(str[itr] == 'M')
        {
          num += 900;
        }
        else
        {
          --itr;
          num += 100;
        }
      }
      else
      {
        num += 100;
        break;
      }
    }
    else if(str[itr] == 'V')
    {
      num += 5;
    }
    else if(str[itr] == 'L')
    {
      num += 50;
    }
    else if(str[itr] == 'D')
    {
      num += 500;
    }
    else if(str[itr] == 'M')
    {
      num += 1000;
    }
    ++itr;
  }
  return num;
}

int main(void)
{
  char *str = (char *)calloc(8,sizeof(*str));
  scanf("%s",str);
  while((getchar()) != '\n');
  int res = romanToInt(str);
  free(str);
  printf("%d\n",res);
  return EXIT_SUCCESS;
}
