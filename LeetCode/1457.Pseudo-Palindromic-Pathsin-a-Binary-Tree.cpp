// 1457. Pseudo-Palindromic Paths in a Binary Tree

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

    int solve(TreeNode* root, unordered_map<int,int>& mp) {
        if(!root) return 0;

        if(!root->left && !root->right) {
            int c = 0;
            mp[root->val]++;
            for(auto i : mp) c += (i.second % 2);
            mp[root->val]--;
            return c <= 1 ? 1 : 0;
        }

        mp[root->val]++;
        int l = solve(root->left , mp);
        int r = solve(root->right , mp);
        mp[root->val]--;
        
        return l + r;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> mp;
        return solve(root, mp);
    }
};
