class Solution {
public:

    void helper(TreeNode* root, vector<int>& ans) {
        if(root) {
            if(root->left) helper(root->left,ans);
            ans.push_back(root->val);
            if(root->right) helper(root->right,ans);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};
