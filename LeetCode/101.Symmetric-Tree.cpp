// 101. Symmetric Tree

class Solution {
public:
    bool dfs(TreeNode* l, TreeNode* r) {
        if(!l && !r) return true;
        if(!l || !r) return false;
        if(l->val != r->val) return false;
        return dfs(l->left, r->right) && dfs(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }
};
