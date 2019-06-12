/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;

// count the nodes to keep track with respect to rev grp node count
// details below
int getCount(Node *head)
{
    Node *itr = head;
    int count = 0;

    while(itr != NULL)
    {
        ++count;
        itr = itr->next;
    }

    return count;
}

// uses O(nodeCount-k) space and O(n) time complexity
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
    Node *newHead = NULL;
    if(head == NULL ||  k == 0)
    {
        return head;
    }

    // create an array to track heads of rev LL groups
    Node **revHead = (Node **)malloc(1*sizeof(*revHead));
    Node *prev = NULL;
    Node *next = NULL;
    Node *itr = head;

    int len = 0; // ptr idx to dynamically update the revHead array
    int c = 0; // count to group count
    int nCount = getCount(head); // get count of nodes in LL
    int crCount = 0; // this count keeps track of number of nodes grouped together
    // in case the (nodeCount - currCount < k) break out of grouping .ie if remaining
    // node count is less than k

    while(itr != NULL)
    {
        c = 0;
        // check if remaining node count is less than k
        if((nCount - crCount) >= k)
        {
            // if yes iterate and rev the nodes to form a temp rev LL with k nodes
            // reversed and store the head of the list in arr
            while(itr != NULL && c < k)
            {
                next = itr->next;
                itr->next = prev;
                prev = itr;
                itr = next;
                ++c;
            }
        }
        else
        {
            // if the remaining node count is less than k then set the curr node
            // as head of this grp and set itr to NULL to break out of iteration
            prev = itr;
            itr = NULL;
        }

        if(len > 0)
        {
            revHead = (Node **)realloc(revHead,sizeof(*revHead)*(len+1));
        }
        revHead[len++] = prev;

        prev = NULL;
        next = NULL;
        crCount += c;
    }

    c = 0;
    newHead = revHead[0];
    // now iterate the grouped LL and point the next of each LL's lastnode to the
    // head of next group; continue till all grps are addressed;
    while(c < len)
    {
        itr = revHead[c];

        while(itr->next != NULL)
        {
            itr = itr->next;
        }
        ++c;
        if(c < len)
        {
            itr->next = revHead[c];
        }
        else
        {
            itr->next = NULL;
        }
    }

    free(revHead);
    return newHead;
}
