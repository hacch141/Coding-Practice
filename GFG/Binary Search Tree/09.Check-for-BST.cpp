// Check for BST

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    bool solve(Node* root, int minVal, int maxVal) {
        if(!root) return true;
        
        if(root -> data <= minVal || root -> data >= maxVal) return false;
        
        bool l = solve(root -> left, minVal, root -> data);
        bool r = solve(root -> right, root -> data, maxVal);
        
        return l && r;
    }
    
    bool isBST(Node* root) 
    {
        // Your code here
        return solve(root,INT_MIN,INT_MAX);
    }
};

// T : O(N)
// S : O(1)
