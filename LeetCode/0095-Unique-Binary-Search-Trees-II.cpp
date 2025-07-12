// 95. Unique Binary Search Trees II

class Solution {
public:
    vector<TreeNode*> solve(int l, int r, map<pair<int,int>, vector<TreeNode*>>& mp) {
        if(l > r) return {NULL};
        if(l == r) return {new TreeNode(l)};

        if(mp.count({l, r})) return mp[{l, r}];

        vector<TreeNode*> ans;
        for(int i = l; i <= r; i++) {
            auto left = solve(l, i - 1, mp);
            auto right = solve(i + 1, r, mp);
            for(auto l : left) {
                for(auto r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return mp[{l, r}] = ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        map<pair<int,int>, vector<TreeNode*>> mp;
        return solve(1, n, mp);
    }
};
