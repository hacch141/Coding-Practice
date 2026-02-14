// Nth node from end of linked list

class Solution {

    public ListNode removeNthFromEnd(ListNode head, int n) {

        ListNode fast = head;
        ListNode slow = head;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast.next;
        }

        // If fast becomes null, we need to remove the head
        if (fast == null) {
            return head.next;
        }

        // Move both pointers until fast reaches the last node
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }

        // Remove the nth node from end
        slow.next = slow.next.next;

        return head;
    }
}

// ==================================================================

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if(!fast) return head->next;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node* dummy = new Node(-1);
    dummy->next = head;
    Node* fast = dummy;
    Node* slow = dummy;
       
    for(int i=1; i<=n; i++) {
        fast = fast->next;
        if(!fast) return -1;
    }
       
    while(fast) {
        slow = slow->next;
        fast = fast->next;
    }
       
    return slow->data;
}

// T : O(N)
// S : O(1)
