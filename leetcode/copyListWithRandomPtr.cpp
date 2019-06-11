/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.


Note:

You must return the copy of the given head as a reference to the cloned list.
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node *create(int val, Node *ref)
    {
        Node *node = (Node *)malloc(1*sizeof(*node));
        node->val = val;
        node->random = ref;
        node->next = NULL;

        return node;
    }

    Node *getRandomNode(Node *head, int val)
    {
        Node *itr = head;

        while(itr != NULL)
        {
            if(itr->val == val)
            {
                break;
            }
            itr = itr->next;
        }

        return itr;
    }


    Node* copyRandomList(Node* head)
    {
        Node *newHead = NULL;
        if(head == NULL)
        {
            return newHead;
        }

        Node *itr = head;
        Node *nItr = NULL;

        while(itr != NULL)
        {
            if(itr == head)
            {
                newHead = create(itr->val,itr->random);
                nItr = newHead;
            }
            else
            {
                nItr->next = create(itr->val,itr->random);
                nItr = nItr->next;
            }
            itr = itr->next;
        }

        itr = head;
        nItr = newHead;

        while(itr != NULL && nItr != NULL)
        {
            if(itr->random == NULL)
            {
                nItr->random = NULL;
            }
            else
            {
                nItr->random = getRandomNode(newHead,itr->random->val);
            }

            itr = itr->next;
            nItr = nItr->next;
        }

        return newHead;
    }
};
