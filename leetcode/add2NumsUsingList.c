/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getLen(struct ListNode *l)
{
    int ret = 0;
    struct ListNode *itr = l;
    while(itr != NULL)
    {
        ++ret;
        itr = itr->next;
    }
    return ret;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL)
    {
        return l2;
    }
    if(l2 == NULL)
    {
        return l1;
    }


    int len1 = getLen(l1);
    int len2 = getLen(l2);

    struct ListNode *retStart;
    struct ListNode *maxItr;
    struct ListNode *minItr;

    int *carry;

    int  startAdd, maxLen;

    if(len1 >= len2)
    {
        carry = (int *)calloc(len1+1,sizeof(*carry));
        maxItr = l1;
        minItr = l2;
        startAdd = len1 - len2;
        maxLen = len1;
    }
    else
    {
        carry = (int *)calloc(len2+1,sizeof(*carry));
        maxItr = l2;
        minItr = l1;
        startAdd = len2 - len1;
        maxLen = len2;
    }

    retStart = maxItr;

    int count = 1;
    int temp;

    startAdd += count;

    while(maxItr != NULL && minItr != NULL)
    {
        if(count >= startAdd)
        {
            temp = maxItr->val + minItr->val;
            if(temp > 9)
            {
                carry[count-1] = 1;
                maxItr->val = temp%10;
            }
            else
            {
                maxItr->val = temp;
            }
            minItr = minItr->next;
        }
        maxItr = maxItr->next;
        ++count;
    }

    int flag;

    struct ListNode *tempStart = retStart;
    label:
        flag = 0;
        maxItr = tempStart;
        struct ListNode *node;
        count = 1;

        if((carry[0] >= 1) && (tempStart == retStart))
        {
            node = (struct ListNode *)calloc(1,sizeof(*node));
            node->val = carry[0];
            node->next = retStart;
            retStart = node;
            carry[0] = 0;
        }
        else if((carry[0] >= 1) && (tempStart != retStart))
        {
            retStart->val += carry[0];
            carry[0] = 0;
        }

        while(maxItr != NULL)
        {
            if(count == maxLen)
            {
                break;
            }

            temp = maxItr->val + carry[count];

            if(count == 1)
            {
                if(temp > 9)
                {
                    maxItr->val = temp%10;
                    carry[count] = 0;
                    carry[count-1] = 1;
                    flag = 1;
                }
                else
                {
                    maxItr->val = temp;
                    carry[count] = 0;
                }
            }
            else
            {
                if(temp >= 10)
                {
                    carry[count-1] = 1;
                    carry[count] = 0;
                    temp = temp%10;
                    flag = 1;
                    maxItr->val = temp;
                }
                else
                {
                    maxItr->val = temp;
                    carry[count] = 0;
                }
            }

            maxItr = maxItr->next;
            ++count;
        }

    if(flag == 1)
    {
        goto label;
    }
    free(carry);
    return retStart;
}
