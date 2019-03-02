/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head)
{
    // my code
//     if(head == NULL || head->next == NULL)
//     {
//         return head;
//     }

//     struct ListNode *itr = head;
//     struct ListNode **arr = (struct ListNode **)malloc(100*sizeof(*arr));
//     arr[0] = itr;
//     int count = 1;
//     while(itr->next != NULL)
//     {
//         itr = itr->next;
//         arr[count] = itr;
//         ++count;

//     }

//     int mid = count/2;

//     struct ListNode *ret = arr[mid];
//     free(arr);
//     return ret;

    struct ListNode *first = head;
    struct ListNode *second = head;

    while(first != NULL)
    {
        first = first->next;
        if(!first)
        {
            return second;
        }
        second = second->next;
        if(!(first->next))
        {
            return second;
        }
        first = first->next;
    }
    return second;
}
