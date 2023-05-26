// Find the first node of loop in linked list

class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        if(!head->next) return -1;
        
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }
        
        if(!fast) return -1;
        
        fast = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast->data;
    }
};

// T : O(N)
// S : O(1)
