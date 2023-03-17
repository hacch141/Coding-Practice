// 437. Path Sum III

class Solution {
public:

    void helper(TreeNode* root, long long& prefix, unordered_map<long long,int>& mp, int& targetSum, int& cnt) {
        if(root) {
            prefix += root->val;

            if(prefix==targetSum) cnt++;
            if(mp.find(prefix-targetSum)!=mp.end()) cnt += mp[prefix-targetSum];

            mp[prefix]++;

            if(root->left) helper(root->left,prefix,mp,targetSum,cnt);
            if(root->right) helper(root->right,prefix,mp,targetSum,cnt);

            mp[prefix]--;
            if(mp[prefix]==0) mp.erase(prefix);

            prefix -= root->val;
        }
        return;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mp;
        int cnt = 0;
        long long prefix = 0;
        helper(root,prefix,mp,targetSum,cnt);
        return cnt;
    }
};
