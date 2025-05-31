// 129. Sum Root to Leaf Numbers

class Solution {
public:
    int dfs(TreeNode* root, int num, int& ans) {
        if(!root) return 0;
        num *= 10;
        num += root->val;
        if(!root->left && !root->right) return num;
        int l = dfs(root->left, num, ans);
        int r = dfs(root->right, num, ans);
        return l + r;
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        return dfs(root, 0, ans);
    }
};
