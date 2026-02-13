// Detect Loop in linked list

class Solution {

    public boolean detectLoop(Node head) {

        if (head == null || head.next == null) return false;

        Node slow = head;
        Node fast = head;

        while (fast.next != null && fast.next.next != null) {

            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) return true;
        }

        return false;
    }
}

// =================================================================

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        if(head==NULL || head->next==NULL) return false;
        Node* slow = head;
        Node* fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast =fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

// T : O(N)
// S : O(1)
