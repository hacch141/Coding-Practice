// 951. Flip Equivalent Binary Trees

class Solution {
public:
    bool dfs(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if(!root1 || !root2 || (root1->val != root2->val)) return false;

        bool flip = dfs(root1->left, root2->right) && dfs(root1->right, root2->left);
        bool no_flip = dfs(root1->left, root2->left) && dfs(root1->right, root2->right);

        return flip || no_flip;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return dfs(root1, root2);
    }
};
