// 404. Sum of Left Leaves

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int solve(TreeNode* root, bool left) {
        if(!root) return 0;
        if(!root->left && !root->right) return left ? root->val : 0;
        int l = 0, r = 0;
        l = solve(root->left, true);
        r = solve(root->right, false);
        return l + r;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, false);
    }
};
