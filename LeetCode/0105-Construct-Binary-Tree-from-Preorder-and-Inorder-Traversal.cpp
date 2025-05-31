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

// OR
class Solution {
public:
    TreeNode* helper(vector<int>& inorder, int start, int end, vector<int>& postorder, int rootIdx) {
        if(start>end || rootIdx<0) return NULL;
        TreeNode* curr = new TreeNode(postorder[rootIdx]);
        int inIdx = 0;
        int num;
        for(int i=start; i<=end; i++) {
            if(inorder[i]==curr->val) {
                inIdx = i;
                num = end-i;
                break;
            }
        }
        curr->left = helper(inorder,start,inIdx-1,postorder,rootIdx-num-1);
        curr->right = helper(inorder,inIdx+1,end,postorder,rootIdx-1);
        return curr;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size()-1, postorder, inorder.size()-1);
    }
};
