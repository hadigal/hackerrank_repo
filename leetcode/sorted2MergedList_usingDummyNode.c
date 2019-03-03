/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// struct ListNode *createNode(int data)
// {
//     struct ListNode *node = (struct ListNode *)calloc(1,sizeof(*node));
//     node->val = data;
//     node->next = NULL;
//     return node;
// }

// struct ListNode *addEnd(struct ListNode *start,struct ListNode *nextNode)
// {
//     if(start ==  NULL)
//     {
//         start = nextNode;
//         return start;
//     }

//     struct ListNode *itr = start;

//     while(itr->next != NULL)
//     {
//         itr = itr->next;
//     }
//     itr->next = nextNode;

//     return start;
// }

void move(struct ListNode **dest, struct ListNode **src)
{
    struct ListNode *temp = *src;
    *src = temp->next;
    temp->next = *dest;
    *dest = temp;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
//     struct ListNode *start1, *start2, *newList = NULL, *itr1, *itr2, *temp;
    // if(!l1)
    // {
    //     return l2;
    // }
    // if(!l2)
    // {
    //     return l1;
    // }

// //     itr1 = l1;
// //     itr2 = l2;

// //     uint8_t flag1 = 0;
// //     uint8_t flag2 = 0;

// //     while((itr1 != NULL) && (itr2 != NULL))
// //     {
// //         if(itr1->val < itr2->val)
// //         {
// //             temp = createNode(itr1->val);
// //             newList = addEnd(newList,temp);
// //             itr1 = itr1->next;
// //             if(itr1 == NULL)
// //             {
// //                 flag1 = 1;
// //                 break;
// //             }
// //         }
// //         else if(itr1->val > itr2->val)
// //         {
// //             temp = createNode(itr2->val);
// //             newList = addEnd(newList,temp);
// //             itr2 = itr2->next;
// //             if(itr2 == NULL)
// //             {
// //                 flag2 = 1;
// //                 break;
// //             }
// //         }
// //         else
// //         {
// //             temp = createNode(itr1->val);
// //             newList = addEnd(newList,temp);
// //             temp = createNode(itr2->val);
// //             newList = addEnd(newList,temp);
// //             itr1 = itr1->next;
// //             if(itr1 ==  NULL)
// //             {
// //                 flag1 = 1;
// //             }
// //             itr2 = itr2->next;
// //             if(itr2 == NULL)
// //             {
// //                 flag2 = 1;
// //             }
// //         }
// //     }

// //     if((flag1 == 0) && (flag2 == 1))
// //     {
// //         while(itr1 != NULL)
// //         {
// //             temp = createNode(itr1->val);
// //             newList = addEnd(newList,temp);
// //             itr1 = itr1->next;

// //         }
// //     }
// //     else if((flag1 == 1) && (flag2 == 0))
// //     {
// //         while(itr2 != NULL)
// //         {
// //             temp = createNode(itr2->val);
// //             newList = addEnd(newList,temp);
// //             itr2 = itr2->next;
// //         }
// //     }

// //     return newList;


//     struct ListNode *retStart = NULL;

//     if(l1->val <= l2->val)
//     {
//         retStart = l1;
//         retStart->next = mergeTwoLists(l1->next,l2);
//     }
//     else
//     {
//         retStart = l2;
//         retStart->next = mergeTwoLists(l1,l2->next);
//     }

//     return retStart;

    struct ListNode dummy;
    struct ListNode *ret = &dummy;
    dummy.next = NULL;

    while(1)
    {
        if(l1 == NULL)
        {
           ret->next = l2;
           break;

        }
        else if(l2 == NULL)
        {
            ret->next = l1;
            break;
        }

        if(l1->val <= l2->val)
        {
            move(&(ret->next),&l1);
        }
        else
        {
            move(&(ret->next),&l2);
        }

        ret = ret->next;
    }
    return (dummy.next);
}
