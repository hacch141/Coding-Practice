// 1373. Maximum Sum BST in Binary Tree

class Solution {
public:
    vector<int> dfs(TreeNode* root, int& mx) {
        if(!root) return {INT_MAX, INT_MIN, 0, 1};

        if(!root->left && !root->right) {
            mx = max(mx, root->val);
            return {root->val, root->val, root->val, 1};
        }

        auto l = dfs(root->left, mx);
        auto r = dfs(root->right, mx);

        if(l[1] >= root->val || r[0] <= root->val || !l[3] || !r[3]) {
            return {0, 0, 0, 0};
        }

        int sum = l[2] + r[2] + root->val;
        mx = max(mx, sum);

        return {min(l[0], root->val), max(r[1], root->val), sum, 1};
    }

    int maxSumBST(TreeNode* root) {
        int mx = 0;
        dfs(root, mx);
        return mx;
    }
};
