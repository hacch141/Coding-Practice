// Check if Linked List is Palindrome

class Solution {

    public Node rev(Node head) {

        if (head == null || head.next == null) return head;

        Node prev = null;
        Node curr = head;

        while (curr != null) {
            Node next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    public boolean isPalindrome(Node head) {

        if (head == null || head.next == null) return true;

        Node slow = head;
        Node fast = head;

        // Find middle
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Reverse second half
        slow.next = rev(slow.next);

        Node second = slow.next;
        Node first = head;

        // Compare halves
        while (second != null) {
            if (second.data != first.data) return false;
            second = second.next;
            first = first.next;
        }

        return true;
    }
}

// ==========================================================================

class Solution{
  public:
  
    Node* rev(Node* head) {
        if(!head || !head->next) return head;
        Node* prev = NULL;
        Node* curr = head;
        while(curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(!head || !head->next) return true;
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = rev(slow->next);
        slow = slow->next;
        fast = head;
        
        while(slow) {
            if(slow->data != fast->data) return false;
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
};

// T : O(N)
// S : O(1)
