#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hasGroupsSizeX(int *deck, int deckSize)
{
  int pairFlag = 0, checkFlag = 0;
  int itr1 = 0, itr2 = 0;
  int currLen,prevLen = 0;
  int *placeHolder = (int *)calloc(deckSize,sizeof(*placeHolder));

  while(itr1 < deckSize)
  {
    if(itr1 != 0 && placeHolder[itr1] == 1)
    {
      ++itr1;
      continue;
    }
    prevLen = currLen;
    currLen = 0;
    itr2 = 0;
    while(itr2 < deckSize)
    {
      if(deck[itr1] == deck[itr2])
      {
        placeHolder[itr2]  = 1;
        ++currLen;
      }
      ++itr2;
    }
    if(currLen == 1)
    {
      pairFlag = 1;
      break;
    }
    if(itr1 != 0)
    {
      // printf("%d\tprevlen:%d\titr:%d\n",currLen,prevLen,itr1);
      if(currLen == prevLen || (currLen > prevLen && (currLen % prevLen == 0) || ((currLen > prevLen && (currLen % prevLen == 0)))
      {
        ++itr1;
        continue;
      }
      if(currLen > prevLen && (currLen % prevLen != 0))
      {
        if(currLen % 2 == 0 &&  prevLen %2 == 0)
        {
          goto label;
        }
        else if(prevLen % 3 == 0 && currLen % 3 == 0)
        {
          goto label;
        }
        else if(prevLen % 5 == 0 && currLen % 5 == 0)
        {
          goto label;
        }
        else if(prevLen % 7 == 0 && currLen % 7 == 0)
        {
          goto label;
        }
        pairFlag = 1;
        break;
      }
      else if(prevLen > currLen && (prevLen%currLen != 0))
      {
        if(currLen % 2 == 0 &&  prevLen %2 == 0)
        {
          goto label;
        }
        else if(prevLen % 3 == 0 && currLen % 3 == 0)
        {
          goto label;
        }
        else if(prevLen % 5 == 0 && currLen % 5 == 0)
        {
          goto label;
        }
        else if(prevLen % 7 == 0 && currLen % 7 == 0)
        {
          goto label;
        }
        pairFlag = 1;
        break;
      }
    }
    label: ++itr1;
  }
  free(placeHolder);
  if(pairFlag == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int *arr;
  int len = 10;
  arr= (int *)calloc(len,sizeof(*arr));
  for(int itr = 0; itr < len;++itr)
  {
    scanf("%d",arr+itr);
  }
  bool res = hasGroupsSizeX(arr,len);
  printf(res ? "true\n":"false\n");
  free(arr);
  return EXIT_SUCCESS;
}
