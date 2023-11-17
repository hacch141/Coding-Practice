// 501. Find Mode in Binary Search Tree

class Solution {
public:

    void solve(TreeNode* root, int& prev, int& freq, int& maxFreq, vector<int>& ans) {
        if(!root) return;

        solve(root->left,prev,freq,maxFreq,ans);
        if(prev == root->val) {
            freq++;
        }
        else {
            freq = 1;
        }

        if(freq == maxFreq) {
            ans.push_back(root->val);
        }
        else if(freq > maxFreq) {
            maxFreq = freq;
            ans = {root->val};
        }

        prev = root->val;
        solve(root->right,prev,freq,maxFreq,ans);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        int prev = -1e9;
        int freq = 1;
        int maxFreq = 1;
        solve(root,prev,freq,maxFreq,ans);
        return ans;
    }
};


// ===========================================================================


// using map
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
