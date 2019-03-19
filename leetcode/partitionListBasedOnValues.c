/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//struct ListNode *add(struct ListNode *prev, int data)
struct ListNode *add(int data)
{
    struct ListNode *node = (struct ListNode *)calloc(1,sizeof(*node));
    node->val = data;
    // if(prev != NULL)
    // {
    //     prev->next = node;
    // }
    // else
    // {
    //     node->next = NULL;
    //     prev = node;
    // }
    node->next = NULL;
    return node;
}

struct ListNode* partition(struct ListNode* head, int x)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *prevLess = NULL;
    struct ListNode *prevGreater = NULL;
    struct ListNode *itr = head;
    struct ListNode *newHead = prevLess;

    struct ListNode *tmpHead = prevGreater;

    while(itr != NULL)
    {
        if(itr->val < x)
        {
            if(prevLess == NULL)
            {
                prevLess = add(itr->val);
                newHead = prevLess;
            }
            else
            {
                prevLess->next = add(itr->val);
                prevLess = prevLess->next;
            }
        }
        else
        {
            if(prevGreater == NULL)
            {
                prevGreater = add(itr->val);
                tmpHead = prevGreater;
            }
            else
            {
                prevGreater->next = add(itr->val);
                prevGreater = prevGreater->next;
            }
        }
        itr = itr->next;
    }

    if(newHead == NULL)
    {
        return tmpHead;
    }
    prevLess->next = tmpHead;
    return newHead;
}
