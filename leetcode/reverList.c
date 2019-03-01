struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    struct ListNode *prev = NULL;
    struct ListNode *itr = head;
    struct ListNode *temp;

    while(itr->next != NULL)
    {
        temp = itr;
        itr = itr->next;
        temp->next = prev;
        prev = temp;
    }

    itr->next = prev;
    head = itr;
    return head;
}
