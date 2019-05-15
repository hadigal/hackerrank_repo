/**************************** geeksforgeeks *******************************

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct Node
{
int data;
Node* next;
};
****************************************************************************/

//The function removes the loop from the linked list if present
//You are required to complete this method
void removeTheLoop(Node *head)
{
     //Your code here
     if(head == NULL || head->next == NULL)
     {
         return;
     }

     Node *slow = head;
     Node *fast = head;
     int flg = 0;

     while(fast != NULL && fast->next != NULL && slow != NULL)
     {
         slow = slow->next;
         fast = fast->next->next;

         if(fast == slow)
         {
             flg = 1;
             break;
         }
     }

     if(flg == 1)
     {
         slow = head;

         while(fast != slow)
         {
             fast = fast->next;
             slow = slow->next;
         }

         fast = fast->next;

         while(fast->next != slow)
         {
             fast = fast->next;
         }

         fast->next = NULL;
     }
     return;
}
