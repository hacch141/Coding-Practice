// Construct Tree from Inorder & Preorder

class Solution {
    int ptr = 0;

    public TreeNode build(int l, int r, int[] inorder, int[] preorder) {
        if (l > r || ptr >= preorder.length) return null;

        TreeNode root = new TreeNode(preorder[ptr++]);
        int ind = -1;
        for (int i = l; i <= r; i++) {
            if (inorder[i] == root.val) {
                ind = i;
                break;
            }
        }

        if (ind == -1) return root;

        root.left = build(l, ind - 1, inorder, preorder);
        root.right = build(ind + 1, r, inorder, preorder);

        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        int n = preorder.length;
        return build(0, n - 1, inorder, preorder);
    }
}

// =============================================================

class Solution{
    public:
    Node* build(int in[], int is, int ie, int pre[], int ps, int pe, map<int,queue<int>>& inmp) {
        if(is>ie || ps>pe) return NULL;
        
        Node* root = new Node(pre[ps]);
        int inRoot = inmp[pre[ps]].front();
        inmp[pre[ps]].pop();
        int numsLeft = inRoot - is;
        
        root->left = build(in,is,inRoot-1,pre,ps+1,ps+numsLeft,inmp);
        root->right = build(in,inRoot+1,ie,pre,ps+numsLeft+1,pe,inmp);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        map<int,queue<int>> inmp;
        for(int i=0; i<n; i++) {
            inmp[in[i]].push(i);
        }
        return build(in,0,n-1,pre,0,n-1,inmp);
    }
};
