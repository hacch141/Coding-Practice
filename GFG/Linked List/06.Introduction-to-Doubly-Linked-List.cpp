// Introduction to Doubly Linked List

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        Node* dummy = new Node(-1);
        Node* start = dummy;
        
        for(auto i : arr) {
            start->next = new Node(i);
            start->next->prev = start;
            start = start->next;
        }
        
        return dummy->next;
    }
};

// T : O(N)
// S : O(N)
