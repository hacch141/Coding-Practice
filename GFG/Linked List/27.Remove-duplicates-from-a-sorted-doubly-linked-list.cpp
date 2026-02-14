// Remove duplicates from a sorted doubly linked list

class Solution {

    Node removeDuplicates(Node head) {

        if (head == null || head.next == null)
            return head;

        Node curr = head;

        while (curr != null && curr.next != null) {

            if (curr.data == curr.next.data) {

                curr.next = curr.next.next;

                if (curr.next != null) {
                    curr.next.prev = curr;
                }
            } 
            else {
                curr = curr.next;
            }
        }

        return head;
    }
}

// ===========================================================================

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
