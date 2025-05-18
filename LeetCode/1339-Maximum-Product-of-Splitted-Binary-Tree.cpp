// 1339. Maximum Product of Splitted Binary Tree

class Solution {
public:
    long long get_total(TreeNode* root) {
        if(!root) return 0;
        return (1LL * root->val) + get_total(root->left) + get_total(root->right);
    }

    int dfs(TreeNode* root, long long& mx_prod, long long& total) {
        if(!root) return 0;
        long long l = dfs(root->left, mx_prod, total);
        long long r = dfs(root->right, mx_prod, total);
        long long sum_subtree = (1LL * root->val) + l + r;
        mx_prod = max(mx_prod, sum_subtree * (total - sum_subtree));
        return sum_subtree;
    }

    int maxProduct(TreeNode* root) {
        long long total = get_total(root), mx_prod = 0, MOD = 1e9 + 7;
        dfs(root, mx_prod, total);
        mx_prod %= MOD;
        return mx_prod;
    }
};
