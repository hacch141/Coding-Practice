// 501. Find Mode in Binary Search Tree

class Solution {
public:

    void helper(TreeNode* root, unordered_map<int,int>& mp) {
        if(root) {
            mp[root->val]++;
            if(root->left) helper(root->left,mp);
            if(root->right) helper(root->right,mp);
        }
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        helper(root,mp);

        int maxfreq = INT_MIN;
        for(auto i : mp) {
            maxfreq = max(maxfreq,i.second);
        }

        vector<int> ans;
        for(auto i : mp) {
            if(i.second == maxfreq) {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};
