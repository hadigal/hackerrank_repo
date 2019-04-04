typedef struct Node
{
    int val;
    struct Node *next;
}NODE;

NODE *create(int val)
{
    NODE *node = (NODE *)calloc(1,sizeof(*node));

    if(node == NULL)
    {
        //printf("error in calloc\n");
        return node;
    }

    node->val = val;
    node->next = NULL;

    return node;
}

void stackPush(NODE **head, int val)
{
    if(*head == NULL)
    {
        //printf("empty-->push\n");
    }

    NODE *node = create(val);
    node->next = *head;
    *head = node;

    return;
}

int stackPop(NODE **head)
{
    if(*head == NULL)
    {
        //printf("empty-->pop\n");
        return INT_MIN;
    }

    int ret;
    NODE *tmp = *head;

    *head = tmp->next;
    ret = tmp->val;
    free(tmp);

    return ret;
}

void display(NODE *head)
{
    NODE *itr = head;

    while(itr != NULL)
    {
        //printf("node:%d\n",itr->val);
        itr = itr->next;
    }

    return;
}

typedef struct
{
    NODE *stack1;
    NODE *stack2;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize)
{
    MyQueue *queue = (MyQueue *)calloc(1,sizeof(*queue));

    if(queue == NULL)
    {
        //printf("error incalloc\n");
        return queue;
    }

    queue->stack1 = NULL;
    queue->stack2 = NULL;

    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
    NODE **itrStack1 = &(obj->stack1);
    NODE **itrStack2 = &(obj->stack2);

    while(*itrStack1 != NULL)
    {
        int val = stackPop(itrStack1);
        if(val != INT_MIN)
        {
            stackPush(itrStack2,val);
        }
    }

    stackPush(itrStack1,x);

    while(*itrStack2 != NULL)
    {
        int val = stackPop(itrStack2);
        if(val != INT_MIN)
        {
            stackPush(itrStack1,val);
        }
    }
    // printf("***\n");
    // display(*itrStack1);
    // printf("---\n");
    // display(obj->stack1);
    // printf("***\n");
    obj->stack1 = *itrStack1;
    return;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
    NODE **stack1 = &(obj->stack1);
    if(*stack1 == NULL)
    {
        return INT_MIN;
    }

    int val = stackPop(stack1);
    return val;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
    NODE **tempStack1 = &(obj->stack1);

    if(*tempStack1 == NULL)
    {
        return INT_MIN;
    }

//     NODE *itr = *tempStack1;

//     while(itr->next != NULL)
//     {
//         printf("val:%d\n",itr->val);
//         itr = itr->next;
//     }

    return ((*tempStack1)->val);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
    if(obj->stack1 == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void myQueueFree(MyQueue* obj)
{
    int ret;
    NODE **itrStack1 = &(obj->stack1);

    while(ret != INT_MIN)
    {
        ret = stackPop(itrStack1);
    }

    return;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * struct MyQueue* obj = myQueueCreate(maxSize);
 * myQueuePush(obj, x);
 * int param_2 = myQueuePop(obj);
 * int param_3 = myQueuePeek(obj);
 * bool param_4 = myQueueEmpty(obj);
 * myQueueFree(obj);
 */
