// 2331. Evaluate Boolean Binary Tree

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

    bool solve(TreeNode* root) {
        int val = root->val;
        if(val == 0 || val == 1) return val;
        bool l = solve(root->left);
        bool r = solve(root->right);
        if(val == 2) return l | r;
        return l & r;
    }

    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};
