// Reverse a linked list

class Solution {
    public Node reverseList(Node head) {

        if (head == null || head.next == null) {
            return head;
        }

        Node rev = reverseList(head.next);

        head.next.next = head;
        head.next = null;

        return rev;
    }
}

// =================================================

class Solution
{
    public:
    
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        if(!head || !head->next) {
            return head;
        }
        Node* rev = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rev;
    }
};

// T : O(N)
// S : O(1) + STACK
