/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getLen(struct ListNode *head)
{
    struct ListNode *itr = head;
    int count = 0;
    while(itr != NULL)
    {
        ++count;
        itr = itr->next;
    }
    return count;
}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if(k == 0 || head == NULL || head->next == NULL)
    {
        return head;
    }

    int nodeCount = getLen(head);
    int val;

    if(nodeCount < k)
    {
        val = (k%nodeCount);
        if(val == 0)
        {
            return head;
        }
    }
    else
    {
        val = k;
    }

    struct ListNode *fast=head->next;
    struct ListNode *slow=head;
    struct ListNode *prev1 = slow;
    struct ListNode *prev2 = NULL;
    int itr = 0;

    while(itr < val)
    {
        while(fast != NULL)
        {
            prev2 = prev1;
            prev1 = fast;
            fast  = fast->next;
            if(fast != NULL)
            {
                slow = slow->next;
                prev2 = prev1;
                prev1 = fast;
                fast  = fast->next;
            }
        }
        prev2->next = prev1->next;
        prev1->next = head;
        head = prev1;
        fast = head->next;
        slow  = head;
        ++itr;
    }
    return head;
}
