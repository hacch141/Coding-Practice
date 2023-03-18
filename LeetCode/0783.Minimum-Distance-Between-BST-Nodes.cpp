// 783. Minimum Distance Between BST Nodes

class Solution {
public:

    int prev = INT_MAX;
    int mindiff = INT_MAX;

    void helper(TreeNode* root) {
        if(root) {
            if(root->left) helper(root->left);
            mindiff = min(mindiff,abs(root->val-prev));
            prev = root->val;
            if(root->right) helper(root->right);
        }
    }

    int minDiffInBST(TreeNode* root) {
        helper(root);
        return mindiff;
    }
};
