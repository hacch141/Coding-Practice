// Introduction to Linked List

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node* dummy = new Node(-1);
        Node* start = dummy;
        for(auto i : arr) {
            start->next = new Node(i);
            start = start->next;
        }
        
        return dummy->next;
    }
};

// T : O(N)
// S : O(N)
