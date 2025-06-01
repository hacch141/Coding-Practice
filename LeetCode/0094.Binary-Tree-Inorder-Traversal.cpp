// 94. Binary Tree Inorder Traversal

class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};
