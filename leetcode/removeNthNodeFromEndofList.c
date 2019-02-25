/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int countNodes(struct ListNode * start)
{
    struct ListNode *itr = start;
    int count = 0;
    while(itr != NULL)
    {
        ++count;
        itr = itr->next;
    }
    return count;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    int count = countNodes(head);
    int stop = count - n;
    if(stop == 0)
    {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int tempCount = 0;
    struct ListNode *itr = head, *temp;

    while(itr->next != NULL)
    {
        ++tempCount;

        if(tempCount == stop)
        {
            temp = itr->next;
            itr->next = temp->next;
            free(temp);
            break;
        }
        itr = itr->next;
    }
    return head;
}
