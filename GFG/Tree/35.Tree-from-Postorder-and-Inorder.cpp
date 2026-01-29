// Tree from Postorder and Inorder

class Solution {
    TreeNode build(int is, int ie, int[] inorder, int ps, int pe, int[] postorder) {
        if (is > ie || ps > pe) return null;

        TreeNode root = new TreeNode(postorder[pe]);

        int ind = -1;
        for (int i = is; i <= ie; i++) {
            if (inorder[i] == root.val) {
                ind = i;
                break;
            }
        }

        int leftSize = ind - is;

        root.left = build(is, ind - 1, inorder, ps, ps + leftSize - 1, postorder);
        root.right = build(ind + 1, ie, inorder, ps + leftSize, pe - 1, postorder);

        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        return build(0, n - 1, inorder, 0, n - 1, postorder);
    }
}

class Solution {
    int ptr;

    TreeNode build(int l, int r, int[] inorder, int[] postorder) {
        if (l > r || ptr < 0) return null;

        TreeNode root = new TreeNode(postorder[ptr--]);

        int ind = -1;
        for (int i = l; i <= r; i++) {
            if (inorder[i] == root.val) {
                ind = i;
                break;
            }
        }

        if (ind == -1) return null;

        root.right = build(ind + 1, r, inorder, postorder);
        root.left = build(l, ind - 1, inorder, postorder);

        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        ptr = n - 1;
        return build(0, n - 1, inorder, postorder);
    }
}

// =================================================================

Node* build(int in[], int is, int ie, int post[], int ps, int pe, map<int,int>& inmp) {
    if(is>ie || ps>pe) return NULL;
    
    Node* root = new Node(post[pe]);
    
    int inRoot = inmp[post[pe]];
    int numsLeft = inRoot-is;
    
    root->left = build(in,is,inRoot-1,post,ps,ps+numsLeft-1,inmp);
    root->right = build(in,inRoot+1,ie,post,ps+numsLeft,pe-1,inmp);
    
    return root;
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    map<int,int> inmp;
    for(int i = 0; i < n; i++) {
        inmp[in[i]] = i;
    }
    return build(in,0,n-1,post,0,n-1,inmp);
}
