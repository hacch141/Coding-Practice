Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(head1 == NULL) {
        return head2;
    }
    if(head2 == NULL) {
        return head1;
    }
    Node* head = NULL;
    Node* tail = NULL;
    if(head1->data < head2->data) {
        head = tail = head1;
        head1 = head1->next;
    }
    else {
        head = tail = head2;
        head2 = head2->next;
    }
    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        else {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }
    if(head1 == NULL) {
        tail->next = head2;
    }
    else {
        tail->next = head1;
    }
    return head;
}  
