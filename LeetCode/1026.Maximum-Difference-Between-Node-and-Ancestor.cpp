// 1026. Maximum Difference Between Node and Ancestor

class Solution {
public:

    void solve(TreeNode* root, int mx, int mn, int& ans) {
        if(!root) return;
        if(mx != -1) {
            ans = max(ans, abs(root->val - mx));
            ans = max(ans, abs(root->val - mn));
        }
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        solve(root->left, mx, mn, ans);
        solve(root->right, mx, mn, ans);
    }

    int maxAncestorDiff(TreeNode* root) {
        int mx = -1, mn = 1e5 + 1, ans = 0;
        solve(root, mx, mn, ans);
        return ans;
    }
};
