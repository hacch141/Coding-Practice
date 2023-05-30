// Remove duplicates from a sorted doubly linked list

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        if(!head->next) return head;
        Node* dummy = head;
        while(dummy && dummy->next) {
            if(dummy->data == dummy->next->data) {
                dummy->next = dummy->next->next;
                if(dummy->next) dummy->next->prev = dummy;
            }
            else {
                dummy = dummy->next;
            }
        }
        return head;
    }
};

// T : O(N)
// S : O(1)
