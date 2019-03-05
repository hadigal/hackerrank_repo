/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head)
{
    struct ListNode *itr = head;
    while(itr)
    {
        if(itr->val == NULL)
        {
            return true;
        }
        itr->val = NULL;
        itr = itr->next;
    }
    return false;
}

// bool checkCycle(struct ListNode **arr, int count, struct ListNode *curr)
// {
//     int mid = count/2;

//     if(arr[mid] == curr)
//     {
//         return true;
//     }

//     int itr1 = 0;
//     int itr2 = count - 1;

//     while((itr1 <= mid -1) && (itr2 >= mid))
//     {
//         if(arr[itr1] == curr || arr[itr2] == curr)
//         {
//             return true;
//         }
//         --itr2;
//         ++itr1;
//     }

//     if(itr1 > (mid-1) && (itr2 != mid))
//     {
//         while(itr2 >= mid)
//         {
//             if(arr[itr2] == curr)
//             {
//                 return true;
//             }
//             --itr2;
//         }
//         return false;
//     }
//     else if(itr1 < (mid-1) && (itr2 < mid))
//     {
//         while(itr1 <= (mid-1))
//         {
//             if(arr[itr1] == curr)
//             {
//                 return true;
//             }
//             ++itr1;
//         }
//         return false;
//     }
//     return false;
// }

// bool hasCycle(struct ListNode *head)
// {
//     if(head == NULL || head->next == NULL)
//     {
//         return false;
//     }

//     bool rc;
//     int count = 1;
//     struct ListNode **arr = (struct ListNode **)calloc(count,sizeof(*arr));
//     arr[0] = head;
//     struct ListNode *itr = head;
//     while(itr->next != NULL)
//     {
//         if(itr != head)
//         {
//             ++count;
//             arr = (struct ListNode **)realloc(arr,sizeof(*arr)*count);
//             arr[count-1] = itr;
//         }
//         rc = checkCycle(arr,count,itr->next);
//         if(rc == true)
//         {
//             free(arr);
//             return true;
//         }
//         itr = itr->next;
//     }
//     free(arr);
//     return false;
// }
