class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head == NULL) {
            return true;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* curr = slow->next;
        Node* prev = NULL;
        while(curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        Node* curr1 = head;
        Node* curr2 = prev;
        
        while(curr2 != NULL) {
            if(curr1->data != curr2->data) {
                return false;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return true;
    }
};
