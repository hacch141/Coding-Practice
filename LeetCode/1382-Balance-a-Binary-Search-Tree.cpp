// 1382. Balance a Binary Search Tree

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

    void dfs(TreeNode* root, vector<int>& v) {
        if(!root) return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }

    TreeNode* solve(vector<int>& v, int l, int h) {
        if(l > h) return NULL;
        int m = (h - l) / 2 + l;
        TreeNode* root = new TreeNode(v[m]);
        root->left = solve(v, l, m - 1);
        root->right = solve(v, m + 1, h);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        return solve(v, 0, v.size() - 1);
    }
};
