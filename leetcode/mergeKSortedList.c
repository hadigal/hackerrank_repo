/********************* prob 23 **************************
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
***********************************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /* used iterative approach. Sorted very index and stored it in master list.
 returned the master list at the end
*/
static inline void move(struct ListNode **dest, struct ListNode **src)
{
    struct ListNode *node = *src;
    *src = node->next;
    node->next = *dest;
    *dest = node;
}

struct ListNode *merge(struct ListNode *list1, struct ListNode *list2)
{
    struct ListNode dummy;
    struct ListNode *dummyTail = &dummy;
    dummy.next = NULL;

    while(1)
    {
        if(list1 == NULL)
        {
            dummyTail->next = list2;
            break;
        }
        else if(list2 == NULL)
        {
            dummyTail->next = list1;
            break;
        }

        if(list1->val <= list2->val)
        {
            move(&(dummyTail->next),&list1);
        }
        else
        {
            move(&(dummyTail->next),&list2);
        }
        dummyTail = dummyTail->next;
    }
    return dummy.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize)
{
    if(listsSize == 0)
    {
        return NULL;
    }

    if(listsSize == 1)
    {
        return lists[0];
    }

    struct ListNode *ret = lists[0];
    for(size_t itr = 1; itr < listsSize; ++itr)
    {
        ret = merge(ret,lists[itr]);
    }
    return ret;
}
