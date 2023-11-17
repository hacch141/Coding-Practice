// 2265. Count Nodes Equal to Average of Subtree

class Solution {
public:

    pair<int,int> solve(TreeNode* root, int& ans) {
        if(!root) {
            return {0,0};
        }

        if(!root->left && !root->right) {
            ans++;
            return {root->val,1};
        }

        auto l = solve(root->left,ans);
        auto r = solve(root->right,ans);

        int sum = l.first + r.first + root->val;
        int n = l.second + r.second + 1;

        int avg = sum/n;
        if(avg == root->val) ans++;

        return {sum,n};
    }    

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};
