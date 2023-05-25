// Reverse a Linked List in groups of given size

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(!head) return NULL;
        
        node* prev = NULL;
        node* curr = head;
        node* next;
        int cnt = 0;
        while(curr && cnt<k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        
        head->next = reverse(next,k);
        
        return prev;
    }
};

// T : O(N)
// S : O(1)
