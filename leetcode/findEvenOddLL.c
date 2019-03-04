/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// struct ListNode *addEven(struct ListNode *oddStart, int val, struct ListNode *oddEndPtr)
// {

// }

// struct ListNode *create(int val)
// {
//     struct ListNode *node = (struct ListNode *)calloc(1,sizeof(*node));
//     node->val = val;
//     node->next = NULL;
//     return node;
// }

struct ListNode* oddEvenList(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }


    //struct ListNode *temp;

    struct ListNode *even = head->next;;
    struct ListNode *odd = head;

    struct ListNode *evenStart = even;
    struct ListNode *oddStart = odd;

    while(odd->next != NULL && even->next != NULL)
    {
      odd->next = even->next;
      even->next = odd->next->next;

      odd = odd->next;
      even = even->next;
    }

    odd->next = evenStart;
    return oddStart;



    // struct ListNode *temp;
    //
    // struct ListNode *even = head->next;;
    // struct ListNode *odd = head;
    //
    // struct ListNode *evenStart = NULL;
    // struct ListNode *oddStart = NULL;
    //
    // struct ListNode *evenEndPtr = NULL;
    // struct ListNode *oddEndPtr = NULL;
    //
    // int count = 1;
    //
    // while(even != NULL && odd != NULL)
    // {
    //     if((count % 2) != 0)
    //     {
    //         temp = create(odd->val);
    //         if(oddStart != NULL)
    //         {
    //             oddEndPtr->next = temp;
    //             oddEndPtr = oddEndPtr->next;
    //         }
    //         else if(oddStart == NULL)
    //         {
    //             oddStart = temp;
    //             oddEndPtr = oddStart;
    //         }
    //
    //         ++count;
    //     }
    //
    //     if(count%2 == 0)
    //     {
    //         temp = create(even->val);
    //         if(evenStart != NULL)
    //         {
    //             evenEndPtr->next = temp;
    //             evenEndPtr = evenEndPtr->next;
    //         }
    //         else if(evenStart == NULL)
    //         {
    //             evenStart = temp;
    //             evenEndPtr = evenStart;
    //         }
    //     }
    //
    //     ++count;
    //     odd = even->next;
    //     if(odd != NULL)
    //     {
    //         even = odd->next;
    //     }
    // }
    //
    // if(even == NULL && odd != NULL)
    // {
    //     temp = create(odd->val);
    //     oddEndPtr->next = temp;
    //     oddEndPtr = oddEndPtr->next;
    // }
    //
    //
    // oddEndPtr->next = evenStart;
    //
    // return oddStart;
}
