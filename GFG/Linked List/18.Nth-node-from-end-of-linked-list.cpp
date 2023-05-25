// Nth node from end of linked list

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
