// Add 1 to a number represented as linked list

class Solution {

    // Reverse a singly linked list
    Node reverse(Node head) {
        if (head == null || head.next == null)
            return head;

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

    // Function to add 1 to a number represented as linked list
    Node addOne(Node head) {

        // Step 1: Reverse the list
        Node rev = reverse(head);
        Node dummy = rev;

        // Step 2: Add 1 to first node
        int carry = (rev.data + 1) / 10;
        int sum = (rev.data + 1) % 10;

        rev.data = sum;
        Node prev = rev;
        rev = rev.next;

        // Step 3: Propagate carry
        while (carry != 0 && rev != null) {
            sum = (rev.data + carry) % 10;
            carry = (rev.data + carry) / 10;
            rev.data = sum;

            prev = rev;
            rev = rev.next;
        }

        // Step 4: If carry still remains
        if (carry != 0) {
            prev.next = new Node(carry);
        }

        // Step 5: Reverse back
        return reverse(dummy);
    }
}

// =====================================================================

class Solution
{
    public:
    
    Node* reverse(Node* head) {
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
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* rev = reverse(head);
        Node* dummy = rev;
        
        int carry = (rev->data + 1)/10;
        int sum = (rev->data + 1)%10;
        
        rev->data = sum;
        Node* prev = rev;
        rev = rev->next;
        
        while(carry && rev) {
            sum = (rev->data + carry)%10;
            carry = (rev->data + carry)/10;
            rev->data = sum;
            prev = rev;
            rev = rev->next;
        }
        if(carry) prev->next = new Node(carry);
        
        return reverse(dummy);
    }
};

// T : O(N)
// S : O(1)
