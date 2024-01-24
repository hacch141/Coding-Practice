// 1457. Pseudo-Palindromic Paths in a Binary Tree

class Solution {
public:

    int solve(TreeNode* root, int& mask) {
        if(!root) return 0;

        if(!root->left && !root->right) {
            mask ^= (1 << root->val);
            bool ans = (mask == 0 || __builtin_popcount(mask) == 1);
            mask ^= (1 << root->val);
            return  ans ? 1 : 0;
        }

        mask ^= (1 << root->val);
        int l = solve(root->left , mask);
        int r = solve(root->right , mask);
        mask ^= (1 << root->val);

        return l + r;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int mask = 0;
        return solve(root, mask);
    }
};



// =============================================================

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
