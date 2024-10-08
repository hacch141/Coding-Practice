// 145. Binary Tree Postorder Traversal

class Solution {    
public:
    void dfs(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        dfs(root->left, ans);
        dfs(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};
