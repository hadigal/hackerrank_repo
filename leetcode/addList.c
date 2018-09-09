/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 #include <stdio.h>
 #include <stdlib.h>

struct ListNode
{
   int val;
   struct ListNode *next;
};

struct ListNode *create(struct ListNode *start)
{
  struct ListNode *Node = (struct ListNode *)calloc(1,sizeof(struct ListNode));
  printf("Enter 1st Node data:\n");
  scanf("%d",&Node->val);
  Node->next = NULL;
  start = Node;
  return start;
}

struct ListNode *createForAdd(struct ListNode *start, int data)
{
  struct ListNode *Node = (struct ListNode *)calloc(1,sizeof(struct ListNode));
  Node->val = data;
  Node->next = NULL;
  start = Node;
  return start;
}

struct ListNode *addAtEnd(struct ListNode *start)
{
  struct ListNode *ptr = start;
  while(ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  struct ListNode *Node = (struct ListNode *)calloc(1,sizeof(struct ListNode));
  printf("Enter data:\n");
  scanf("%d",&Node->val);
  Node->next = ptr->next;
  ptr->next = Node;
  return start;
}

struct ListNode *addAtEndForAdd(struct ListNode *start, int data)
{
  struct ListNode *ptr = start;
  while(ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  struct ListNode *Node = (struct ListNode *)calloc(1,sizeof(struct ListNode));
  Node->val = data;
  Node->next = ptr->next;
  ptr->next = Node;
  return start;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int i = 0;
    unsigned long int j =1, l1Sum = 0, l2Sum = 0, temp_sum;
    //int *l1Arr = (int *)calloc(1,sizeof(int)), *l2Arr = (int *)calloc(1,sizeof(int));
    struct ListNode *ptr = l1;

    while(ptr != NULL)
    {
        temp_sum = j*(ptr->val);
        //printf("l1Arr[%d]:%d\n",i,l1Arr[i]);
        l1Sum = l1Sum + temp_sum;
        //l2Arr[i] = j*(ptr->val);
        ptr = ptr->next;
        if(ptr != NULL)
        {
            j = j*10;
            i++;
            //l1Arr = realloc(l1Arr,(i+1)*sizeof(int));
        }
    }

    int i1 = 0;
    ptr = l2;
    j = 1;

    while(ptr != NULL)
    {
        //l2Arr[i] = j*(ptr->val);
        temp_sum = j*(ptr->val);
        l2Sum = l2Sum + temp_sum;
        ptr = ptr->next;

        if(ptr != NULL)
        {
            j = j*10;
            i1++;
            //l2Arr = realloc(l2Arr,(i+1)*sizeof(int));
        }
    }

    printf("\nl1Sum:%lu\nl2Sum:%lu\n",l1Sum,l2Sum);

    unsigned long int val = l1Sum + l2Sum, temp;
    printf("\nval:%lu\n",val);

    temp = val;

    if(temp == 0)
    {
      struct ListNode *start = NULL;
      start = createForAdd(start,temp);
      return start;
    }

    ptr = NULL;
    struct ListNode * Node,*start = NULL;
    int startFlg = 0;
    while(temp)
    {
        if(startFlg == 0)
        {
          start = createForAdd(start,(temp%10));
        }
        temp = temp/10;
        if(temp != 0)
        {
            start = addAtEndForAdd(start,(temp%10));
            startFlg++;
        }
    }

    return start;
}

void display(struct ListNode *start)
{
  struct ListNode *ptr = start;
  printf("\n[");
  while(ptr != NULL)
  {
    printf("%d,",ptr->val);
    ptr = ptr->next;
  }
  printf("]\n");
}

int main(void)
{
  struct ListNode *start = NULL;
  start = create(start);
  //start = addAtEnd(start);
  //start = addAtEnd(start);
  struct ListNode *l1 = start;
  start = NULL;
  start = create(start);
  start = addAtEnd(start);
  start = addAtEnd(start);
  start = addAtEnd(start);
  start = addAtEnd(start);
  start = addAtEnd(start);
  start = addAtEnd(start);
  start = addAtEnd(start);
  start = addAtEnd(start);
  start = addAtEnd(start);
  struct ListNode *l2 = start;
  display(l1);
  display(l2);
  struct ListNode *val = addTwoNumbers(l1,l2);

  display(val);

  return 0;
}
