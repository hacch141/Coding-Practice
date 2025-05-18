// 872. Leaf-Similar Trees

// DFS
class Solution {
public:
    void get_leaves(TreeNode* root, string& s) {
        if(!root) return;
        if(!root->left && !root->right) {
            s += to_string(root->val) + '_';
            return;
        }
        get_leaves(root->left, s);
        get_leaves(root->right, s);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1, s2;
        get_leaves(root1, s1);
        get_leaves(root2, s2);
        return s1 == s2;
    }
};
