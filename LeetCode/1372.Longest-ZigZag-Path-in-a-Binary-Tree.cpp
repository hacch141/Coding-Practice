// 1372. Longest ZigZag Path in a Binary Tree

class Solution {
public:
    pair<int,int> dfs(TreeNode* root, int& ans) {
        if(!root) return {-1, -1};

        auto l = dfs(root->left, ans);
        auto r = dfs(root->right, ans);

        ans = max(ans, 1 + max(l.second, r.first));
        return {1 + l.second, 1 + r.first};
    }

    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
