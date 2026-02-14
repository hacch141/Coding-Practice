// Find the first node of loop in linked list

class Solution {

    // Function to find first node if the linked list has a loop.
    public int findFirstNode(Node head) {

        if (head == null || head.next == null)
            return -1;

        Node slow = head;
        Node fast = head;

        // Step 1: Detect cycle
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast)
                break;
        }

        // If no cycle
        if (fast == null || fast.next == null)
            return -1;

        // Step 2: Find starting node of cycle
        fast = head;
        while (slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }

        return fast.data;
    }
}

// =====================================================================

class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        if(!head->next) return -1;
        
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }
        
        if(!fast) return -1;
        
        fast = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast->data;
    }
};

// T : O(N)
// S : O(1)
