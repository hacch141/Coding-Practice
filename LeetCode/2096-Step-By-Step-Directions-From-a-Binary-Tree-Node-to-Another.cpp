// 2096. Step-By-Step Directions From a Binary Tree Node to Another

class Solution {
public:
    TreeNode* get_lca(TreeNode* root, int startValue, int destValue) {
        if(!root) return NULL;
        if(root->val == startValue || root->val == destValue) return root;
        TreeNode* l = get_lca(root->left, startValue, destValue);
        TreeNode* r = get_lca(root->right, startValue, destValue);
        return l && r ? root : l ? l : r;
    }

    void get_root_to_val_path(TreeNode* root, int val, string& curr, string& path) {
        if(!root) return;

        if(root->val == val) {
            path = curr;
            return;
        }

        curr.push_back('L');
        get_root_to_val_path(root->left, val, curr, path);
        curr.pop_back();

        curr.push_back('R');
        get_root_to_val_path(root->right, val, curr, path);
        curr.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = get_lca(root, startValue, destValue);
        string up, down, curr = "";
        get_root_to_val_path(lca, startValue, curr, up);
        get_root_to_val_path(lca, destValue, curr, down);
        return string(up.length(), 'U') + down;
    }
};
