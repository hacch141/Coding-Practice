// Delete a Node in Single Linked List

Node* deleteNode(Node *head,int x)
{
    //Your code here
    if(x==1) return head->next;
    
    int cnt = 1;
    Node* dummy = head;
    while(cnt!=x-1 && dummy) {
        dummy = dummy->next;
        cnt++;
    }
    dummy->next = dummy->next->next;
    
    return head;
}

// T : O(N)
// S : O(1)
