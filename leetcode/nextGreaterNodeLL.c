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


// a better solution: worst case o(nlogn)
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

static inline void push(int **stack, int *tf, int val)
{
    ++*tf;
    stack[0][*tf] = val;
    return;
}

static inline int pop(int **stack, int *tf)
{
    int val = stack[0][*tf];
    --*tf;
    return val;
}

// create a ret array list which is at first initialized to linked list member values
// once the array is created start from last element.
// at first copy value at each idx to a var. Now check if stack is empty if not check
// if value at top of stack is <= arr[idx] if yes then pop until top of stack is >
// than arr[idx] or stack empty. Now store the value at top of stack to arr[idx]
// if empty stack store 0. continue until 0th index is reached.
int* nextLargerNodes(struct ListNode* head, int* retSize)
{
    if(head == NULL)
    {
        *retSize = 0;
        return NULL;
    }

    int *ret = (int *)malloc(1*sizeof(*ret));
    int *stack = NULL;
    int tf = -1, sz;

    int len = 0;
    struct ListNode *nitr = head;

    while(nitr != NULL)
    {
        if(len > 0)
        {
            sz = len+1;
            ret = (int *)realloc(ret,sizeof(*ret)*(sz));
        }
        ret[len++] = nitr->val;
        nitr = nitr->next;
    }

    stack = (int *)malloc(len*sizeof(*stack));

    for(int itr = len-1; itr >= 0; --itr)
    {
        int val = ret[itr];

        while(tf > -1 && stack[tf] <= ret[itr])
        {
            pop(&stack,&tf);
        }
        ret[itr] = (tf == -1)?0:stack[tf];

        push(&stack,&tf,val);
    }

    free(stack);
    *retSize = len;
    return ret;
}

// brute force o(n^2) iterative solution
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

int getMax(struct ListNode *head)
{
    struct ListNode *itr = head->next;
    int max = head->val;

    while(itr != NULL)
    {
        if(itr->val > max)
        {
            max = itr->val;
            break;
        }

        itr = itr->next;
    }

    //printf("max:%d\n",max);
    return max;
}

int* nextLargerNodes(struct ListNode* head, int* retSize)
{
    if(head == NULL)
    {
        *retSize = 0;
        return NULL;
    }

    int len = getLen(head);
    int *ret = (int *)malloc(len*sizeof(*ret));
    struct ListNode *itr = head, *prevNode = NULL;
    int prev = -1, max;
    int aItr = 0;


    if(len == 1)
    {
        ret[0] = 0;
        *retSize = 1;
        return ret;
    }

    while(itr != NULL)
    {
        if(prev == -1)
        {
            max = getMax(itr);
            if(max == itr->val)
            {
                ret[aItr] = 0;
            }
            else
            {
                ret[aItr] = max;
            }

            prev = ret[aItr];
        }
        else
        {
            if(prevNode->val < itr->val && itr-prev != itr->val && prev > itr->val)
            {
                ret[aItr] = prev;
            }
            else
            {
                max = getMax(itr);
                if(max == itr->val)
                {
                    ret[aItr] = 0;
                }
                else
                {
                    ret[aItr] = max;
                }
                prev = ret[aItr];
            }
        }

        prevNode = itr;
        itr = itr->next;
        ++aItr;
    }

    *retSize = len;
    return ret;
}
