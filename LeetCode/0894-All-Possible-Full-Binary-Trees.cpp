// 894. All Possible Full Binary Trees

class Solution {
public:
    vector<TreeNode*> solve(int n, unordered_map<int, vector<TreeNode*>>& mp) {
        if(n % 2 == 0) return {};
        if(n == 1) return {new TreeNode(0)};

        if(mp.count(n)) return mp[n];

        vector<TreeNode*> ans;
        for(int i = 1; i < n; i += 2) {
            auto left = solve(i, mp);
            auto right = solve(n - i - 1, mp);
            for(auto l : left) {
                for(auto r : right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return mp[n] = ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int, vector<TreeNode*>> mp;
        return solve(n, mp);
    }
};
