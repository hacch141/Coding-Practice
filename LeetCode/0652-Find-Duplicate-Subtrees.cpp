// 652. Find Duplicate Subtrees

class Solution {
public:
    string dfs(TreeNode* root, unordered_map<string,int>& mp, vector<TreeNode*>& ans) {
        if(!root) return "N";
        string s = to_string(root->val);
        s += "," + dfs(root->left, mp, ans);
        s += "," + dfs(root->right, mp, ans);
        if(mp[s] == 1) ans.push_back(root);
        mp[s]++;
        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> ans;
        dfs(root, mp, ans);
        return ans;
    }
};
