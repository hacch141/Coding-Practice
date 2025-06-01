// 979. Distribute Coins in Binary Tree

class Solution {
public:

    int solve(TreeNode* root, int& ans) {
        if(!root) return 0;
        int l = solve(root->left, ans);
        int r = solve(root->right, ans);
        ans += abs(l) + abs(r);
        return root->val + l + r - 1;
    }

    int distributeCoins(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
