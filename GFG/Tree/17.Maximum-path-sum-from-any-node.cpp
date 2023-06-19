// Maximum path sum from any node

class Solution {
  public:
  
    int solve(Node* root, int& maxi) {
        if(!root) return 0;
        int l = max(0,solve(root->left,maxi));
        int r = max(0,solve(root->right,maxi));
        maxi = max(maxi,root->data+l+r);
        return root->data+max(l,r);
    }
  
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root) {
        // Your code goes here
        int maxi = INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};

// T : O(N)
// S : O(N)
