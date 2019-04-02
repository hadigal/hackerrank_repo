typedef struct Node
{
    int val;
    struct Node *prev;
    struct Node *next;
}Node;

Node *createNode(int val)
{
    Node *node = (Node *)calloc(1,sizeof(*node));
    node->next = NULL;
    node->prev = NULL;
    node->val = val;
    return node;
}

typedef struct
{
    int count;
    struct Node *head;
    struct Node *tail;
}MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate()
{
    MyLinkedList *ll = (MyLinkedList *)calloc(1,sizeof(*ll));
    return ll;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index)
{

    if(obj->head == NULL || index >= obj->count)
    {
        return -1;
    }

    int count = 0;

    Node *itr = obj->head;

    while(itr != NULL)
    {
        if(count == index)
        {
            return itr->val;
        }
        itr = itr->next;
        ++count;
    }
    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val)
{

    Node *new = createNode(val);

    if(obj->head == NULL)
    {
        obj->head = new;
        obj->tail = new;
        obj->count += 1;
        printf("after:%d\n",obj->count);
        return;

    }

    Node *prevHead = obj->head;
    new->next = prevHead;
    prevHead->prev = new;
    obj->head = new;
    obj->count += 1;
    return;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{

    Node *new = createNode(val);

    if(obj->head == NULL)
    {

        obj->head = new;
        obj->tail = new;
        obj->count += 1;
        return;
    }


    Node *prevTail = obj->tail;

    prevTail->next = new;
    new->prev = prevTail;
    new->next = NULL;

    obj->tail = new;
    obj->count += 1;
    return;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val)
{
    if(index == 0)
    {
        myLinkedListAddAtHead(obj,val);
        return;
    }

    if(obj->head == NULL || obj->count < index)
    {
        return;
    }
    else if(index == obj->count)
    {
        myLinkedListAddAtTail(obj, val);
        return;
    }

    //MyLinkedList *itr = obj, *tmp, *node, *prev;

    int count = 0;

    Node *itr = obj->head, *tmp, *node, *prev;

    while(itr != NULL)
    {
        if(count == index)
        {
            tmp = itr->prev;

            node = createNode(val);
            node->prev = tmp;
            //node->next = tmp->next;
            node->next = itr;
            tmp->next = node;
            itr->prev = node;
            obj->count += 1;
            return;
        }
        prev = itr;
        itr = itr->next;
        ++count;
    }

    return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
    if(obj->head == NULL || obj->count <= index)
    {
        return;
    }

    Node *itr = obj->head, *prev, *next, *tmp;
    int count = 0;

    if(index == 0)
    {
        tmp = obj->head;
        next = tmp->next;
        next->prev = tmp->prev;

        obj->head = next;
        free(tmp);
        obj->count -= 1;
        return;
    }
    else if(index == obj->count - 1)
    {
        tmp = obj->tail;
        prev = tmp->prev;
        prev->next = tmp->next;
        obj->tail = prev;
        obj->count -= 1;
        free(tmp);
        return;
    }

    while(itr != NULL)
    {
        if(count == index)
        {
            prev = itr->prev;
            next = itr->next;
            tmp = itr;

            prev->next = next;
            next->prev = prev;
            free(tmp);
            obj->count -= 1;
            return;
        }
        itr = itr->next;
        ++count;
    }
    return;
}

void freeList(Node *head)
{
    Node *itr = head, *next, *tmp;

    while(itr != NULL)
    {
        next = itr->next;
        tmp = itr;
        itr = next;
        free(tmp);
    }
    return;
}

void myLinkedListFree(MyLinkedList* obj)
{

    freeList(obj->head);
    free(obj);
    return;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */
