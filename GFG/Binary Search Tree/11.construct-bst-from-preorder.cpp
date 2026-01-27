// Construct BST from preorder

class Solution {
    int i = 0;

    public TreeNode solve(int[] preorder, int bound) {
        if (i == preorder.length || preorder[i] > bound) return null;
        TreeNode root = new TreeNode(preorder[i++]);

        root.left = solve(preorder, root.val);
        root.right = solve(preorder, bound);
        return root;
    }

    public TreeNode bstFromPreorder(int[] preorder) {
        return solve(preorder, Integer.MAX_VALUE);
    }
}

// ==============================================

class Solution{
public:

    Node* solve(int pre[], int& i, int& n, int bound) {
        if(i == n || pre[i] > bound) return NULL;
        
        Node* root = newNode(pre[i++]);
        root -> left = solve(pre,i,n,root -> data);
        root -> right = solve(pre,i,n,bound);
        
        return root;
    }

    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    {
        //code here
        int i = 0;
        return solve(pre,i,size,INT_MAX);
    }
};

// T : O(N)
// S : O(N)
