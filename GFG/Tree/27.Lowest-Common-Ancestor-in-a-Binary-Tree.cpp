// Lowest Common Ancestor in a Binary Tree

class Solution
{
    public:
    
    Node* solve(Node* root ,int& n1 ,int& n2) {
        if(!root || root->data == n1 || root->data == n2) {
            return root;
        }
        
        Node* l = solve(root->left,n1,n2);
        Node* r = solve(root->right,n1,n2);
        if(l && r) return root;
        if(l) return l;
        return r;
    }
    
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       return solve(root,n1,n2);
    }
};

// T : O(N)
// T : O(H)
