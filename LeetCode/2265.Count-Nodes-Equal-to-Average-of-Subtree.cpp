// 2265. Count Nodes Equal to Average of Subtree

class Solution {
public:
    pair<int,int> dfs(TreeNode* root, int& ans) {
        if(!root) return {0, 0};

        auto l = dfs(root->left, ans);
        auto r = dfs(root->right, ans);

        int sum = root->val + l.first + r.first;
        int cnt_nodes = 1 + l.second + r.second;
        ans += (sum / cnt_nodes) == root->val;

        return {sum, cnt_nodes};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
