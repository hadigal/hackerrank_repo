/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// int find(int *G, int size, int val)
// {
//     for(size_t itr = 0; itr < size; ++itr)
//     {
//         if(val == G[itr])
//         {
//             return 1;
//         }
//     }
//     return 0;
// }


int numComponents(struct ListNode* head, int* G, int GSize)
{
    // if(head == NULL)
    // {
    //     return 0;
    // }

    int ret = 0;

//     if(head->next == NULL)
//     {
//         ret = find(G,GSize, head->val);
//         return ret;
//     }

//     struct ListNode *itr = head;

//     int temp = 0;
//     while(itr != NULL)
//     {
//         int temp2 = find(G,GSize,itr->val);
//         if(temp2 == 1)
//         {
//             temp += temp2;
//         }
//         else
//         {
//             //printf("val:%d\n",itr->val);
//             if(temp > 0)
//             {
//                 ret += 1;
//                 temp = 0;
//             }
//         }
//         itr = itr->next;
//     }

//     if(temp > 0)
//     {
//         ret += 1;
//     }
//     return ret;

    int *map = (int *)malloc(10001*sizeof(*map));
    memset(map,0,10001);

    for(size_t itr1 = 0; itr1 < GSize ; ++itr1)
    {
        map[G[itr1]] = 1;
    }

    struct ListNode *itr = head;

    while(itr != NULL)
    {
        if((itr->val <= 10000) && (map[itr->val] == 1) && (itr->next == NULL || map[itr->next->val] == 0))
        {
            ++ret;
        }
        itr = itr->next;
    }
    free(map);
    return ret;
}
