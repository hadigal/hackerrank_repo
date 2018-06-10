#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char *s;
  s = calloc(1024,sizeof(char));
  if(!s)
  {
    printf("Error:realloc()\n");
  }
  scanf("%[^\n]s",s);
  int str_len = strlen(s)+1;
  if(str_len > 1000)
  {
    printf("Error:strlen(s) > 1000\n");
    exit(EXIT_FAILURE);
  }

  s = realloc(s,str_len*sizeof(char));
  if(!s)
  {
    printf("Failure:realloc(token_size)\n");
    exit(EXIT_FAILURE);
  }
  int i,count_space = 0;
  int *token_size;

  token_size = (int *)calloc(1,sizeof(int));
  if(!token_size)
  {
    printf("Failure:calloc(token_size)\n");
    exit(EXIT_FAILURE);
  }

  int counter = 0;
  for(i = 0; i < str_len; i++)
  {
    counter++;
    if(s[i] == ' ')
    {
      count_space++;
      token_size = realloc(token_size,(count_space+1)*sizeof(int));
      if(!token_size)
      {
        printf("Failure:realloc(token_size)\n");
        exit(EXIT_FAILURE);
      }
      token_size[count_space - 1] = counter - 1;
      counter = 0;
    }
  }
  token_size[count_space] = counter - 1;

  // for tokens
  char **token_blocks;
  token_blocks = (char **)calloc((count_space+1),sizeof(char *));
  int j,count=0;

  // saving the eacch space separated token in a char buff and printing them.
  for(i = 0; i <=count_space; i++ )
  {
    *(token_blocks + i) = (char *)calloc(token_size[count_space],sizeof(char));
    for(j =0; j < token_size[i];j++)
    {
      *(*(token_blocks + i) + j) = s[count];
      count++;
    }
    count += 1;
    printf("%s\n",*(token_blocks + i));
  }
  // freeing the allocated space
  for(i = 0; i <= count_space; i++)
  {
    if(*(token_blocks+i))
    {
      free(*(token_blocks+i));
    }
  }
  if(token_blocks)
  {
    free(token_blocks);
  }
  if(token_size)
  {
    free(token_size);
  }
  return 0;
}
