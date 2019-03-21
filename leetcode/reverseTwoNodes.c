/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *itr1 = head;
    struct ListNode *itr2 = head->next;
    struct ListNode *nextItr = itr2->next;
    struct ListNode *prevItr = NULL;

    while(itr2 != NULL && itr1 != NULL)
    {
        itr1->next = nextItr;
        itr2->next = itr1;

        if(prevItr == NULL)
        {
            head = itr2;
        }
        else
        {
            prevItr->next = itr2;
        }

        prevItr = itr1;
        itr1 = nextItr;
        if(itr1 != NULL)
        {
            itr2 = itr1->next;
            if(itr2 != NULL)
            {
                nextItr = itr2->next;
            }
        }
    }
    return head;
}
