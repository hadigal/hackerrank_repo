/*
Given a (singly) linked list with head node root, write a function to split the
linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have
 a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring
earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input:
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2,
\root.next.next.val = 3, and root.next.next.next = null.

The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


//logic is to first compute the length of the linked list; once we get the now
// compute the w = len/k and rem = len%k. Now create a array of List of size k.
// iterate till k and start storing head of each sub list. At first len of each
// list until last node is reached is equal to (w+(currIdx < rem)?1:0). If end node
// has been reached before the (k-1)th idx of return arr; store NULL at the remaining
// idxs.
typedef struct ListNode Node;

void getLen(Node *head, int *len)
{
    if(head == NULL)
    {
        *len = 0;
        return;
    }
    Node *itr = head;

    while(itr != NULL)
    {
        ++*len;
        itr = itr->next;
    }
}

struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize)
{
    // if(root == NULL)
    // {
    //     *returnSize = 0;
    //     return NULL;
    // }
    int len = 0;
    getLen(root,&len);
    Node **ret = (Node **)malloc(k*sizeof(*ret));

    int w = len/k;
    int r = len%k;
    int itr = 0;
    *returnSize = k;
    Node *nItr = root, *prev = NULL;
    while(itr < k)
    {
        ret[itr] = nItr;
        for(int itr2 = 0; itr2 < (w+((itr < r)?1:0)); ++itr2)
        {
            if(nItr != NULL)
            {
                prev = nItr;
                nItr = nItr->next;
            }
            else
            {
                prev = NULL;
            }
        }


        if(prev != NULL)
        {
            prev->next = NULL;
        }

        ++itr;
    }

    return ret;
}
