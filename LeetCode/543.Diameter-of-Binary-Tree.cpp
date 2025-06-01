// 543. Diameter of Binary Tree

class Solution {
public:
    int dfs(TreeNode* root, int& ans) {
        if(!root) return 0;
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        ans = max(ans, l + r);
        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
