/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    struct ListNode *prev =NULL;
    struct ListNode *itr = head;
    struct ListNode *next = NULL;

    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    int count = 0;

    struct ListNode *tmpTail = NULL;
    struct ListNode *prevHead = NULL;

    while(itr != NULL)
    {
        ++count;
        if(count == m -1)
        {
            prevHead = itr;
        }

        if(count == m)
        {
            tmpTail = itr;
            next = itr->next;
            prev = itr;
            itr = itr->next;
        }
        else if(count > m && count <= n)
        {
            next = itr->next;
            itr->next = prev;
            prev = itr;
            itr = next;
            if(count == n)
            {
                tmpTail->next = next;
                if(prevHead != NULL)
                {
                    prevHead->next = prev;
                }
                else
                {
                    prevHead = prev;
                }
                break;
            }
        }
        else
        {
            itr = itr->next;
        }
    }

    if(m == 1 && itr == NULL)
    {
        return prev;
    }
    else if(m == 1 && itr != NULL)
    {
        return prevHead;
    }

    return head;
}
