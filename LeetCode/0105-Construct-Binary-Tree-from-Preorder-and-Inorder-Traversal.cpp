// 105. Construct Binary Tree from Preorder and Inorder Traversal

// DFS
class Solution {
public:
    TreeNode* build(int& ptr, int& n, int l, int r, vector<int>& preorder, vector<int>& inorder) {
        if(ptr >= n || l > r) return NULL;
        TreeNode* root = new TreeNode(preorder[ptr]);
        ptr++;
        int ind;
        for(int i = l; i <= r; i++) {
            if(inorder[i] == preorder[ptr - 1]) {
                ind = i;
                break;
            }
        }
        root->left = build(ptr, n, l, ind - 1, preorder, inorder);
        root->right = build(ptr, n, ind + 1, r, preorder, inorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(), ptr = 0;
        return build(ptr, n,  0, n - 1, preorder, inorder);
    }
};
