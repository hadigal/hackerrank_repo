#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// lexicographic_sort without strcmp function
int my_lexicographic_sort(const char* a,const char* b)
{
  int len1 = strlen(a);
  int len2 = strlen(b);

  int sht_len, flag, eq_flg, i = 0;
  if(len1 < len2)
  {
    sht_len = len1;
  }
  else if(len2 < len1)
  {
    sht_len = len2;
  }
  else
  {
    sht_len = len1;
  }
  while(i < sht_len)
  {
    if(a[i] < b[i])
    {
      flag = 1;
      break;
    }
    else if(a[i] == b[i])
    {
      i++;
      eq_flg++;
    }
    else if(a[i] > b[i])
    {
      flag = 0;
      break;
    }
  }
  if((i == sht_len) && (len1 == len2) && (eq_flg == i))
  {
    flag = 0;
  }
  else if((i == sht_len) && (len1 > len2))
  {
    flag = 0;
  }
  else if((i == sht_len) && (len1 < len2))
  {
    flag = 1;
  }
  return flag;
}

// lexicographic_sort with strcmp function
int lexicographic_sort(const char* a,const char* b)
{
  int res = strcmp(a,b);
  if(res == 0 || res > 0)
  {
    res = 0;
  }
  else
  {
    res = 1;
  }
  return res;
}

int lexicographic_sort_reverse(const char* a, const char* b)
{
  int flag = lexicographic_sort(a,b);
  if(flag == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int sort_by_length(const char* a, const char* b)
{
  int len1 = strlen(a);
  int len2 = strlen(b);
  int flag = 0;

  if(len1 < len2)
  {
    flag = 1;
  }
  else if(len1 == len2)
  {
    flag = lexicographic_sort(a,b);
  }
  return flag;
}

int count_distinct_char(const char *a,int len)
{
  int count = 0;

  while(*a != '\0')
  {
    if(!strchr(a+1,*a))
    {
      count++;
    }
    a++;
  }
  return count;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b)
{
  int len1 = strlen(a);
  int len2 = strlen(b);
  int d1,d2,flag;

  d1 = count_distinct_char(a,len1);
  d2 = count_distinct_char(b,len2);

  if(d1 == d2)
  {
    flag = lexicographic_sort(a,b);
  }
  else if(d1 - d2 < 0)
  {
    flag = 1;
  }
  else
  {
    flag = 0;
  }
  return flag;
}

void bubble_sort_string(char ** arr, int len, int (* fp)(const char * a,const char *b))
{
  int i,j,sort_flag;
  for(i = 0; i < len -1; i++)
  {
    sort_flag = 0;
    for(j = 0; j < len - 1 - i; j++)
    {
      if(fp(arr[j+1],arr[j]) == 1)
      {
        char *temp;
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        sort_flag++;
      }
    }
    if(sort_flag == 0)
    {
      break;
    }
  }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a,const char* b))
{
  bubble_sort_string(arr,len,cmp_func);
}

int main()
{
  int n;
  scanf("%d", &n);

  char** arr;
	arr = (char**)malloc(n * sizeof(char*));

  for(int i = 0; i < n; i++)
  {
    *(arr + i) = malloc(1024 * sizeof(char));
    scanf("%s", *(arr + i));
    *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
  }

  string_sort(arr, n, lexicographic_sort);
  printf("\n***************** lexicographic_sort *****************\n");
  for(int i = 0; i < n; i++)
  {
    printf("%s\n", arr[i]);
  }
  printf("\n");

  string_sort(arr, n, lexicographic_sort_reverse);
  printf("\n************* lexicographic_sort_reverse *************\n");
  for(int i = 0; i < n; i++)
  {
    printf("%s\n", arr[i]);
  }
  printf("\n");

  string_sort(arr, n, sort_by_length);
  printf("\n******************* sort_by_length *******************\n");
  for(int i = 0; i < n; i++)
  {
    printf("%s\n", arr[i]);
  }
  printf("\n");

  string_sort(arr, n, sort_by_number_of_distinct_characters);
  printf("\n******* sort_by_number_of_distinct_characters ********\n");
  for(int i = 0; i < n; i++)
  {
    printf("%s\n", arr[i]);
  }
  printf("\n");
  for(int j = 0; j < n; j++)
  {
    if(arr[j])
    {
      free(arr[j]);
    }
  }
  if(arr)
  {
    free(arr);
  }
}
