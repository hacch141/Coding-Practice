// Find pairs with given sum in doubly linked list

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> ans;
        Node* start = head;
        Node* end = head;
        while(end->next) {
            end = end->next;
        }
        
        while(start!=end) {
            int sum = start->data + end->data;
            if(sum == target) {
                ans.push_back({start->data,end->data});
                start = start->next;
            }
            else if(sum < target) {
                start = start->next;
            }
            else {
                end = end->prev;
            }
        }
        
        return ans;
    }
};

// T : O(N)
// S : O(1)
