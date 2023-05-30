// Find length of Loop

int countNodesinLoop(struct Node *head)
{
    // Code here
    if(!head->next) return 0;
    
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) break;
    }
    
    if(!fast || !fast->next) return 0;
    
    int cnt = 1;
    slow = slow->next;
    while(slow != fast) {
        cnt++;
        slow = slow->next;
    }
    
    return cnt;
}

// T : O(N)
// S : O(1)
