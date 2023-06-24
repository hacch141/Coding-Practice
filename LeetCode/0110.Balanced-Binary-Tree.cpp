// 110. Balanced Binary Tree

class Solution {
public:

    int solve(TreeNode* root) {
        if(!root) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        if(l==-1 || r==-1 || abs(l-r)>1) return -1;
        return 1 + max(l,r);
    }

    bool isBalanced(TreeNode* root) {
        return solve(root) == -1 ? false : true;
    }
};
