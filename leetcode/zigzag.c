#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFF 128

static char *convert(char *str, int numRows)
{
  unsigned int len  = strlen(str);
  if(str[0] == 0 || numRows == 1 || len <= numRows)
  {
    return str;
  }
  //retStr = (char *)calloc(len+1,sizeof(*retStr));
  char **zzStr = (char **)calloc(numRows,sizeof(*zzStr));
  int defFlag = 0,cFlag = 0;
  int row=0,col=0;
  int itr = 0;
  int *rowLen = (int *)calloc(numRows,sizeof(*rowLen));
  while(itr < len)
  {
    if(defFlag < numRows)
    {
      zzStr[defFlag] = (char *)calloc(len,sizeof(*zzStr[defFlag]));
      ++defFlag;
    }
    zzStr[row][col] = str[itr];
    if(cFlag == 0)
    {
      ++row;
      if(itr < len - 1)
      {
        rowLen[row] = col;
      }
      if(row == numRows - 1)
      {
        cFlag = 1;
        ++itr;
        continue;
      }
      ++itr;
      continue;
    }
    else
    {
      --row;
      ++col;
      if(itr < len - 1)
      {
        rowLen[row] = col;
      }
      if(row == 0)
      {
        cFlag = 0;
        if(itr < len - 1)
        {
          rowLen[0] = col;
        }
        //++row;
      }
    }
    ++itr;
  }

  int itr1 = 0,itr2, itr3 = 0;
  unsigned int rLen;
  while(itr1 < numRows)
  {
    //rLen = strlen(zzStr[itr]);
    itr2 = 0;
    while(itr2 <= rowLen[itr1])
    {
      if(zzStr[itr1][itr2] && (itr3 < len))
      {
        str[itr3] = zzStr[itr1][itr2];
        ++itr3;
      }
      ++itr2;
    }
    free(zzStr[itr1]);
    ++itr1;
  }
  free(zzStr);
  free(rowLen);
  return str;
}

int main(void)
{
  char *str;
  int row;
  str = (char *)calloc(MAX_BUFF,sizeof(*str));
  scanf("%[^\n]s",str);
  while((getchar()) != '\n');
  scanf("%d",&row);
  char *res = convert(str,row);
  printf("%s\n",res);
  free(str);
  return EXIT_SUCCESS;
}
