typedef struct Node
{
    int val;
    int min;
    struct Node *next;
}Node;

Node *create(int val)
{
    Node *node = (Node *)calloc(1,sizeof(*node));
    if(node == NULL)
    {
        return node;
    }

    node->val = val;
    //node->min = 0;
    node->next =  NULL;

    return node;
}

typedef struct
{
    Node *stack;
} MinStack;

/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize)
{
    MinStack *stack = (MinStack *)calloc(1,sizeof(*stack));

    stack->stack = NULL;

    return stack;
}

void minStackPush(MinStack* obj, int x)
{
    Node **head = &(obj->stack);
    Node *node = create(x);

    if(*head == NULL)
    {
        node->min = x;
        printf("node->min:%d",node->min);
        node->next = NULL;
        *head = node;
        return;
    }

    int currMin = (*head)->min;
    node->next = *head;
    *head = node;

    if(x < currMin)
    {
        (*head)->min = x;
    }
    else
    {
        (*head)->min = currMin;
    }

}

void minStackPop(MinStack* obj)
{
    Node **head = &(obj->stack);
    if(*head == NULL)
    {
        return;
    }

    Node *temp = *head;

    *head = temp->next;
    int newMin;
    if(temp->min == temp->val)
    {
        Node *itr = temp->next;
        if(itr != NULL)
        {
            newMin = itr->val;
            while(itr != NULL)
            {
                if(itr->val < newMin)
                {
                    newMin = itr->val;
                }
                itr = itr->next;
            }
            temp->min = newMin;
        }
    }
    if(*head != NULL)
    {
        (*head)->min = temp->min;
    }
    free(temp);
}

int minStackTop(MinStack* obj)
{
    Node *stackHead = obj->stack;
    if(stackHead == NULL)
    {
        return INT_MIN;
    }
    return (stackHead->val);
}

int minStackGetMin(MinStack* obj)
{
    Node *stackHead = obj->stack;
    if(stackHead == NULL)
    {
        return INT_MIN;
    }
    return (stackHead->min);
}

void minStackFree(MinStack* obj)
{
    Node **stackHead = &(obj->stack);

    if(stackHead == NULL)
    {
        free(obj);
        return;
    }

    while(*stackHead != NULL)
    {
        Node *tmp = *stackHead;
        *stackHead = tmp->next;
        free(tmp);
    }
    free(obj);
    return;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */
