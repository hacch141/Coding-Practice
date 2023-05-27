// Search in Linked List

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        // Code here
        int cnt = 1;
        while(cnt<=n && head) {
            if(head->data == key) return true;
            head = head->next;
            cnt++;
        }
        
        return false;
    }
};

// T : O(N)
// S : O(1)
