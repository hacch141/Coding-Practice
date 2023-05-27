// Reverse a Doubly Linked List

Node* reverseDLL(Node * head)
{
    //Your code here
    Node* prev = NULL;
    Node* curr = head;
    while(curr) {
        Node* next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
}

// T : O(N)
// S : O(1)
