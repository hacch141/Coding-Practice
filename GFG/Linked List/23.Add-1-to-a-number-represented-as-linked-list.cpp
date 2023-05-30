// Add 1 to a number represented as linked list

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
