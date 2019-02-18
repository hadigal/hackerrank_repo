struct Node
{
    char c;
    struct Node *next;
};

struct Node *stackStart = NULL;

void push(char data)
{
    struct Node *temp = (struct Node *)calloc(1,sizeof(*temp));
    if(stackStart == NULL)
    {
        temp->c = data;
        temp->next = NULL;
        stackStart = temp;
        //return start;
        return;
    }
    temp->c = data;
    temp->next = stackStart;
    stackStart = temp;
    //return start;
    return;
}

char pop()
{
    if(stackStart == NULL)
    {
        return '\0';
    }
    struct Node *temp = stackStart->next;
    struct Node *freeNode = stackStart;
    char ret = stackStart->c;
    stackStart = temp;
    free(freeNode);
    return ret;
}

bool isValid(char* s)
{
  int balFlag = 0;
  char ret;
  int i = 0;
  if(s[i] == '\0')
  {
      return true;
  }
  while(s[i] != '\0')
  {
      if(s[i] =='{' || s[i] == '[' || s[i] == '(')
      {

          push(s[i]);

          ++i;
          continue;
      }
      if(s[i] == '}' || s[i] == ')' || s[i] == ']')
      {
          if(stackStart == NULL)
          {

              balFlag = 1;
              break;
              //return 0;
          }

          ret = pop(stackStart);

          if(s[i] == '}' && ret != '{')
          {

              balFlag = 1;
              break;
              //return false;
          }
          else if(s[i] == ')' && ret != '(')
          {

              balFlag = 1;
              //return false;
              break;
          }
          else if(s[i] == ']' && ret != '[')
          {
              balFlag = 1;
              break;
              //return false;
          }
          ++i;
          if(s[i] == '\0')
              break;
          continue;
      }
  }

  if(stackStart != NULL || balFlag == 1)
  {
      while(stackStart != NULL)
      {
          ret = pop(stackStart);
      }
      //free(stackStart);
      return false;
  }
  else
  {
      while(stackStart != NULL)
      {
          ret = pop(stackStart);
      }
      return true;
  }
}
