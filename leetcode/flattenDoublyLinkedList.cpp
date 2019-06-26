/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:

    // logic is to check if the give child node has a another child node or not
    // if yes then recursively remove the solve the child nodes and flatten the
    // the child node DLL.

    // Logic to flatten store the ptr to next node to new ptr; now store the current
    // child node if any for the current node to new ptr. Make the prev ptr of
    // child node point to current node. Make next ptr of current node pt to child node
    // now recursively call on the child node to fetch its last node.
    // Once we get the final last node of child list make the nextPtr prev node pt
    // to the lastNode returned and mark the next of last node to nextPtr.
    Node *getLastChNode(Node **ch)
    {
        Node *ret = NULL;
        Node *itr = *ch;
        Node *next = NULL, *tmpCh = NULL, *chLast = NULL;

        while(itr->next != NULL)
        {
            if(itr->child != NULL)
            {
                next = itr->next;
                tmpCh = itr->child;
                tmpCh->prev = itr;
                itr->next = tmpCh;
                itr->child = NULL;
                chLast = getLastChNode(&tmpCh);
                chLast->next = next;
                next->prev = chLast;
                itr = next;
            }
            else
            {
                itr = itr->next;
            }
        }

        if(itr->child != NULL)
        {
            next = itr->next;
            tmpCh = itr->child;
            tmpCh->prev = itr;
            itr->next = tmpCh;
            itr->child = NULL;
            chLast = getLastChNode(&tmpCh);
            chLast->next = next;
            // if(next != NULL)
            // {
            //     next->prev = chLast;
            // }
            return chLast;
        }

        return itr;
    }

    Node* flatten(Node* head)
    {
        if(head == NULL)
        {
            return head;
        }

        Node *currNext = NULL, *chLast = NULL, *itr = head;
        Node *ch = NULL;

        while(itr != NULL)
        {
            if(itr->child != NULL)
            {
                currNext = itr->next;
                ch = itr->child;
                itr->next = ch;
                itr->child = NULL;
                ch->prev = itr;
                chLast = getLastChNode(&ch);
                chLast->next = currNext;
                if(currNext != NULL)
                {
                    currNext->prev = chLast;
                }
                itr = currNext;
            }
            else
            {
                itr = itr->next;
            }
        }

        return head;
    }
};
