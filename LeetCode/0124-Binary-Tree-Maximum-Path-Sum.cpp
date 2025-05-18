// 124. Binary Tree Maximum Path Sum

class Solution {
public:
    int dfs(TreeNode* root, int& mx_path_sum) {
        if(!root) return 0;
        int l = dfs(root->left, mx_path_sum);
        int r = dfs(root->right, mx_path_sum);
        mx_path_sum = max(mx_path_sum, root->val + l + r);
        return max(0, root->val + max(l, r));
    }

    int maxPathSum(TreeNode* root) {
        int mx_path_sum = INT_MIN;
        dfs(root, mx_path_sum);
        return mx_path_sum;
    }
};
