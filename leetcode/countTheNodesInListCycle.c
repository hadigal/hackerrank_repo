/*
Structure of the node of the linked list is as
struct Node
{
	int data;
	struct Node* next;
};
*/
// Your task is to complete the function this function
// function should return the size of the loop
int countNodesinLoop(struct Node *head)
{
     // Code here
     if(head == NULL || head->next == NULL)
     {
         return 0;
     }

     struct Node *slow = head;
     struct Node *fast = head;

     int count = 0;
     int flg = 0;

     while(fast != NULL && fast->next != NULL && slow != NULL)
     {
         slow = slow->next;
         fast = fast->next->next;

         if(slow == fast)
         {
             flg = 1;
             break;
         }
     }

     if(flg == 1)
     {
         slow = head;
         while(slow != fast)
         {
             slow = slow->next;
             fast = fast->next;
         }

         fast = fast->next;
         while(fast != slow)
         {
             ++count;
             fast = fast->next;
         }
         return (count + 1);
     }
     return 0;
}
