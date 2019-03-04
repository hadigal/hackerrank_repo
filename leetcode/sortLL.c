/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// struct ListNode *merge(struct ListNode *l, struct ListNode *r)
// {
//     struct ListNode *ret;
//     if(l == NULL)
//     {
//         return r;
//     }
//     else if(r == NULL)
//     {
//         return l;
//     }

//     if(l->val <= r->val)
//     {
//         ret = l;
//         ret->next = merge(l->next,r);
//     }
//     else
//     {
//         ret = r;
//         ret->next = merge(l,r->next);
//     }
//     return ret;
// }

void move(struct ListNode **dest, struct ListNode **src)
{
    struct ListNode *temp = *src;
    *src = temp->next;
    temp->next = *dest;
    *dest = temp;
}

struct ListNode *merge(struct ListNode *l, struct ListNode *r)
{
    struct ListNode dummy;
    struct ListNode *temp = &dummy;
    dummy.next = NULL;

    while(1)
    {
        if(l == NULL)
        {
            temp->next = r;
            break;
        }
        else if(r == NULL)
        {
            temp->next = l;
            break;
        }
        if(l->val <= r->val)
        {
            //temp = l;
            move(&(temp->next),&l);
        }
        else
        {
            move(&(temp->next),&r);
        }
        temp = temp->next;
    }
    return dummy.next;
}


// void partition(struct ListNode *head, struct ListNode **src, struct ListNode **mid)
// {
//     struct ListNode *fast = head->next;
//     struct ListNode *slow = head;

//     *src = head;

//     while(fast != NULL)
//     {
//         fast = fast->next;
//         if(fast != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next;
//         }
//     }
//     *mid = slow->next;
//     slow->next = NULL;
// }


void mergeSort(struct ListNode **src)
{
    struct ListNode *head = *src;
    if(head == NULL || head->next == NULL)
    {
        return;
    }

    struct ListNode *l;
    struct ListNode *r;


    struct ListNode *fast = head->next;
    struct ListNode *slow = head;

    //*src = head;
    l = head;

    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    //*mid = slow->next;
    r = slow->next;
    slow->next = NULL;

    //partition(head,&l,&r);

    mergeSort(&l);
    mergeSort(&r);

    *src = merge(l,r);
}


struct ListNode* sortList(struct ListNode* head)
{
    mergeSort(&head);
    return head;
}
