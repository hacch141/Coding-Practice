// 106. Construct Binary Tree from Inorder and Postorder Traversal

class Solution {
public:
    TreeNode* dfs(int& ind, int l, int r, vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>& mp) {
        if(l > r) return NULL;
        int val = postorder[ind];
        TreeNode* root = new TreeNode(val);
        ind--;
        root->right = dfs(ind, mp[val] + 1, r, inorder, postorder, mp);
        root->left = dfs(ind, l, mp[val] - 1, inorder, postorder, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(), ind = n - 1;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[inorder[i]] = i;
        return dfs(ind, 0, n - 1, inorder, postorder, mp);
    }
};
