// 1325. Delete Leaves With a Given Value

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

    bool solve(TreeNode* root, int target) {
        if(!root) return true;

        bool l = solve(root->left, target);
        bool r = solve(root->right, target);

        if(l) root->left = NULL;
        if(r) root->right = NULL;

        return (l && r && root->val == target);
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool isRootDeleted = solve(root, target);
        return isRootDeleted ? NULL : root;
    }
};
