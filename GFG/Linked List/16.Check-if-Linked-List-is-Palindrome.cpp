// Check if Linked List is Palindrome

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
