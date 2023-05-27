// Count nodes of linked list

class Solution
{
    public:
    //Function to count nodes of a linked list.
    int getCount(struct Node* head){
    
        //Code here
        int cnt = 1;
        while(head->next) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
};

// T : O(N)
// S : O(1)
