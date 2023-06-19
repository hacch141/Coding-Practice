// Check for Balanced Tree

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int solve(Node* root) {
        if(!root) return 0;
        int lh = solve(root->left);
        int rh = solve(root->right);
        if(lh==-1 || rh == -1 || abs(lh-rh)>1) return -1;
        return max(lh,rh)+1;
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root) {
        //  Your Code here
        return IsBal(root) != -1;
    }
};

// T : O(N)
// S : O(N)
