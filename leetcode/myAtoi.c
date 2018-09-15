#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define MAX_BUFF 128

int myAtoi(char *str)
{
  int itr = 0, stIdx, stpIdx, sig = 0,flag =0;
  int strFlag = 0, numFlag = 0, digCount = 0, zeroFlag = 0;

  if((str[itr] < 48 && str[itr] != 32 && str[itr] != 43 && str[itr] != 45) || str[itr] > 57)
  {
    return 0;
  }

  while(str[itr] != '\0')
  {
    if(str[itr] == ' ' || str[itr] == '+')
    {
      strFlag = 1;
      if(str[itr] == '+')
      {
        //sigFlag = 1;
        if(str[itr+1] < 48 || str[itr+1] > 57)
        {
          break;
        }
      }
      else if(numFlag == 1 || zeroFlag == 1)
      {
        break;
      }
      ++itr;
      continue;
    }
    else if(str[itr] == '-')
    {
      sig = 1;
      strFlag = 1;
      if(str[itr+1] < 48 || str[itr+1] > 57)
      {
        break;
      }
      else if(numFlag == 1 || zeroFlag == 1)
      {
        break;
      }
      ++itr;
      continue;
    }
    else if((str[itr] < 48 && str[itr] != 32 && str[itr] != 43 && str[itr] != 45) || str[itr] > 57)
    {
      if(numFlag == 1)
      {
         stpIdx = itr-1;
      }
      strFlag = 1;
      break;
    }
    else
    {
      ++digCount;
      if(digCount > 10)
      {
        break;
      }
      if(numFlag == 0)
      {
        if(str[itr] == '0')
        {
          zeroFlag = 1;
          --digCount;
          ++itr;
          continue;
        }
        stIdx = itr;
        numFlag = 1;
        if(str[itr+1] < 48 || str[itr+1] > 57)
        {
          stpIdx = itr;
          break;
        }
        ++itr;
        continue;
      }
      else
      {
        if(str[itr+1] < 48 || str[itr+1] > 57)
        {
          stpIdx = itr;
          break;
        }
        ++itr;
      }
    }
  }
  if(strFlag == 1 && numFlag ==0 && zeroFlag == 0)
  {
    return 0;
  }

  if(digCount > 10)
  {
    if(sig == 1)
    {
      return INT_MIN;
    }
    else
    {
      return INT_MAX;
    }
  }

  digCount -= 1;
  long long int res = 0;
  long long int temp;
  int tenPow[9] = {10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
  for(int itr1 = stIdx; itr1 <= stpIdx; itr1++)
  {
    // sscanf(str+itr1,"%d",&temp);
    temp = str[itr1] - '0';
    if(digCount > 0)
    {
      res += (temp*tenPow[digCount-1]);
      --digCount;
    }
    else
    {

      res += temp;
    }
  }
  if(sig == 1)
  {
    res *= -1;
    if(res < INT_MIN)
    {
      return INT_MIN;
    }
    else
    {
      return (int)res;
    }
  }
  else
  {
    if(res > INT_MAX)
    {
      return INT_MAX;
    }
    else
    {
      return (int)res;
    }
  }
}

int main(void)
{
  char *str;
  str = (char *)calloc(MAX_BUFF,sizeof(*str));
  scanf("%[^\n]s",str);
  while((getchar()) != '\n');
  int res = myAtoi(str);
  printf("%d\n",res);
  free(str);
  return EXIT_SUCCESS;
}
