// 987. Vertical Order Traversal of a Binary Tree

class Solution {
public:
    void dfs(TreeNode* root, map<int, vector<int>>& mp, int x, int y, map<pair<int, int>, multiset<int>>& mpp) {
        if (!root) return;

        mpp[{x, y}].insert(root->val);

        dfs(root->left, mp, x - 1, y + 1, mpp);
        dfs(root->right, mp, x + 1, y + 1, mpp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> mp;
        map<pair<int, int>, multiset<int>> mpp;

        dfs(root, mp, 0, 0, mpp);

        for(auto& it : mpp) {
            int x = it.first.first;
            for(int val : it.second) {
                mp[x].push_back(val);
            }
        }

        vector<vector<int>> ans;
        for (auto& it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
