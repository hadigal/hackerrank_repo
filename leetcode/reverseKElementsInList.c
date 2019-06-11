/*
  Reverse a linked list
  The input list will have at least one element
  Return pointer to head of reverse linked list
  Node is defined as
  struct node
  {
     int data;
     struct Node *next;
  }
*/
struct node *create(int val)
{
    struct node *node = (struct node *)malloc(1*sizeof(*node));
    node->data = val;
    node->next = NULL;
}

struct node *reverse (struct node *head, int k)
{
  if(head == NULL || head->next == NULL)
  {
      return head;
  }
  // Complete this method
  struct node **arr = (struct node **)malloc(1*sizeof(*arr));
  int len = 0;
  struct node *itr = head, *prev = NULL, *next = NULL;
  int c;
  struct node *tmpHead = NULL;

  while(itr != NULL)
  {
      c = 0;
      while(itr != NULL && c < k)
      {
          next = itr->next;
          itr->next = prev;
          prev = itr;
          itr = next;
          ++c;
      }

      if(len > 0)
      {
          arr = (struct node **)realloc(arr,sizeof(*arr)*(len+1));
      }
      arr[len++] = prev;
      prev = NULL;
      next = NULL;
  }

  struct node *tmpitr = NULL, *node = NULL;
  c = 0;

  while(c < len)
  {
      itr = arr[c++];
      while(itr != NULL)
      {
          node = create(itr->data);
          if(tmpHead == NULL)
          {
              tmpHead = node;
              tmpitr = tmpHead;
          }
          else
          {
              tmpitr->next = node;
              tmpitr = tmpitr->next;
          }

          itr = itr->next;
      }
  }

  free(arr);
  return tmpHead;
}
