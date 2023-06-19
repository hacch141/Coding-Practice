// Symmetric Tree

class Solution{
    public:
    
    bool solve(Node* n1, Node*n2) {
      if(!n1 && !n2) return true;
      if(!n1 || !n2) return false;
      if(n1->data != n2->data) return false;
      bool l = solve(n1->left,n2->right);
      bool r = solve(n1->right,n2->left);
      return l && r;
    }
    
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(!root) return true;
	    return solve(root->left,root->right);
    }
};

// T : O(N)
// S : O(N)
