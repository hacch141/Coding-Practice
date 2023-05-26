// Delete Middle of Linked List

Node* deleteMid(Node* head)
{
    // Your Code Here
    if(!head->next) return NULL;
    if(!head->next->next) {
        head->next = NULL;
        return head;
    }
    
    Node* dummy = new Node(-1);
    dummy->next = head;
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast && fast->next) {
        dummy = dummy->next;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    dummy->next = dummy->next->next;
    
    return head;
}

// T : O(N)
// S : O(1)
