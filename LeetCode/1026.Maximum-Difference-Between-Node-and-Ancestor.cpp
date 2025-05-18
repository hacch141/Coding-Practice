// 1026. Maximum Difference Between Node and Ancestor

class Solution {
public:
    int dfs(TreeNode* root, int mn, int mx) {
        if(!root) return mx - mn;
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        int l = dfs(root->left, mn, mx);
        int r = dfs(root->right, mn, mx);
        return max(l, r);
    }

    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, 1e6, -1);
    }
};

// down to top
class Solution {
public:
    pair<int,int> dfs(TreeNode* root, int& mx_diff) {
        if(!root) return {1e6, -1};
        if(!root->left && !root->right) return {root->val, root->val};

        auto l = dfs(root->left, mx_diff);
        auto r = dfs(root->right, mx_diff);

        int mn = min(l.first, r.first);
        int mx = max(l.second, r.second);

        mx_diff = max(mx_diff, abs(root->val - mn));
        mx_diff = max(mx_diff, abs(root->val - mx));

        mn = min(mn, root->val);
        mx = max(mx, root->val);
        return {mn, mx};
    }

    int maxAncestorDiff(TreeNode* root) {
        int mx_diff = 0;
        dfs(root, mx_diff);
        return mx_diff;
    }
};

// top to down
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
