// 129. Sum Root to Leaf Numbers

class Solution {
public:
    void dfs(TreeNode* root, int num, int& ans) {
        if(!root) return;
        num *= 10;
        num += root->val;
        if(!root->left && !root->right) ans += num;
        dfs(root->left, num, ans);
        dfs(root->right, num, ans);
        num /= 10;
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};
