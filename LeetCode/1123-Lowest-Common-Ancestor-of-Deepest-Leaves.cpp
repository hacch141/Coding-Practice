// 1123. Lowest Common Ancestor of Deepest Leaves

class Solution {
public:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if(!root) return {nullptr, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        if(l.second > r.second) {
            return {l.first, l.second + 1};
        }
        else if(l.second < r.second) {
            return {r.first, r.second + 1};
        }
        return {root, l.second + 1};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};

// 
class Solution {
public:
    int get_height(TreeNode* root) {
        if(!root) return -1;
        int l = get_height(root->left);
        int r = get_height(root->right);
        return 1 + max(l, r);
    }

    bool dfs(int curr_height, int& mx_height, TreeNode* root, TreeNode*& ans) {
        if(!root) return false;

        bool l = dfs(curr_height + 1, mx_height, root->left, ans);
        bool r = dfs(curr_height + 1, mx_height, root->right, ans);

        if((l && r) || curr_height == mx_height) {
            ans = root;
            return true;
        }

        return l || r;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int mx_height = get_height(root);
        TreeNode* ans;
        dfs(0, mx_height, root, ans);
        return ans;
    }
};
