#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 128

char *fix_fgets_newline(char *str)
{
  int count = 0;
  while(1)
  {
    if(str[count] == '\n')
    {
      str[count] = '\0';
      break;
    }
    count++;
  }
  return str;
}

int str_len(char const * str)
{
  int count = 0;
  while(1)
  {
    if(str[count] == '\0')
    {
      break;
    }
    count++;
  }
  return count;
}

char *str_cpy(char * dest, const char *src, int len)
{
  int i;
  for(i = 0; i < len; i++)
  {
    dest[i] = src[i];
  }
  dest[len] = '\0';
  return dest;
}

int str_cmp(const char *str1,const char *str2)
{
  unsigned int len1, len2;
  len1 = str_len(str1);
  len2 = str_len(str2);

  int flag = 0;
  for(int i = 0; i < len1 + 1; i++)
  {
    if(str1[i] != str2[i])
    {
      flag = 1;
      goto final;
    }
  }
  if(flag == 0)
  {
    return flag;
  }
  final:
    return len1 - len2;
}

char *str_rev(char * str)
{
  int len;
  len = str_len(str);
  char *rev = (char *)malloc((len+1)*sizeof(char));
  int j = 0;
  for(int i = len - 1; i >= 0; i--)
  {
    rev[j] = str[i];
    j++;
  }
  rev[len] = '\0';
  return rev;
}

char *str_cat(char *str1, const char *str2)
{
  unsigned int len1 = str_len(str1);
  unsigned int str2_len = str_len(str2);
  // +1 TO HOLD THE '\0' CHAR AT THE END
  int len2 = len1 + str2_len + 1;
  if(len2 > BUFF)
  {
    printf("WARNING:Undefined result str2+str1 > BUFF!\n");
    len2 = BUFF;
  }

  int i,j = 0;
  for(i = len1; i < len2; i++)
  {
    str1[i] = str2[j];
    j++;
  }

  str1[len2 - 1] = '\0';
  return str1;
}

int main(void)
{
  char *str1;
  str1 = (char *)malloc((BUFF+1)*sizeof(char));
  int len;
  char *gets_data = fgets(str1,BUFF,stdin);
  if(!gets_data)
  {
    printf("Error: i/p\n");
    return EXIT_FAILURE;
  }

  str1 = fix_fgets_newline(str1);

  //strlen
  len = str_len(str1);

  printf("\n*************************** OUTPUT ***************************\n");
  printf("Str:\n%s\n",str1);
  printf("Len:%d\n",len);

  //strcpy
  char *str2 = (char *)malloc((len+1)*sizeof(char));
  str2 = str_cpy(str2,str1,len+1);
  printf("Str_cpy:\n%s\n",str2);

  // strcmp
  char *str3;
  str3 = (char *)malloc(BUFF*sizeof(char));
  printf("Enter String for comparison...\n");
  gets_data = fgets(str3,BUFF,stdin);
  if(!gets_data)
  {
    printf("Error in i/p of str3\n");
    return EXIT_FAILURE;
  }
  str3 = fix_fgets_newline(str3);
  int result_cmp = str_cmp(str1,str3);

  if(result_cmp == 0)
  {
    printf("str3 == str1\n");
  }
  else
  {
    printf("STR3 != STR1\n");
  }

  // strrev
  char *rev_str;
  rev_str = str_rev(str1);
  printf("Reversed str:\n%s\n",rev_str);

  //strcat
  char *cat_str;
  cat_str = (char *)malloc(BUFF*sizeof(char));
  printf("Enter the string for concatination:\n");
  if(!fgets(cat_str,BUFF,stdin))
  {
    printf("Error in concatination string i/p\n");
    return EXIT_FAILURE;
  }
  cat_str = fix_fgets_newline(cat_str);

  if(str_len(cat_str) > (BUFF - (str_len(str1) + 1)))
  {
    printf("Warning: Undefined Result!!!\n");
  }
  str_cat(str1,cat_str);
  printf("New Str1 after concatination:\n%s",str1);

  printf("\n**************************************************************\n");
  if(str1)
  {
    free(str1);
  }
  if(str3)
  {
    free(str3);
  }
  if(cat_str)
  {
    free(cat_str);
  }
  free(rev_str);
  return EXIT_SUCCESS;
}
