// 530. Minimum Absolute Difference in BST

class Solution {
public:

    int mini = INT_MAX;
    int prev = INT_MAX;

    void helper(TreeNode* root) {
        if(root) {
            if(root->left) helper(root->left);
            mini = min(mini,abs(root->val - prev));
            prev = root->val;
            if(root->right) helper(root->right);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        helper(root);
        return mini;
    }
};
