// 236. Lowest Common Ancestor of a Binary Tree

// DFS
class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root == p || root == q) return root;
        TreeNode* l = dfs(root->left, p, q);
        TreeNode* r = dfs(root->right, p, q);
        if(l && r) return root;
        if(l) return l;
        if(r) return r;
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};
