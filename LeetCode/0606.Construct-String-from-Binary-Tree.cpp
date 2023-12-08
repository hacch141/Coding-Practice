// 606. Construct String from Binary Tree

class Solution {
public:

    void solve(TreeNode* root, string& ans) {
        if(!root) return;
        ans += to_string(root->val);
        if(root->left || root->right) ans += '(';
        solve(root->left,ans);
        if(root->left || root->right) ans += ')';

        if(root->right) ans += '(';
        solve(root->right,ans);
        if(root->right) ans += ')';
        return;
    }

    string tree2str(TreeNode* root) {
        string ans = "";
        solve(root,ans);
        return ans;
    }
};
