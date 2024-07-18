// 1530. Number of Good Leaf Nodes Pairs

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<int> merge(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size(), n2 = v2.size(), p1 = 0, p2 = 0;
        vector<int> v;
        while(p1 < n1 && p2 < n2) {
            if(v1[p1] < v2[p2]) {
                if(v1[p1] + 1 <= 10) v.push_back(v1[p1] + 1);
                p1++;
            }
            else {
                if(v2[p2] + 1 <= 10) v.push_back(v2[p2] + 1);
                p2++;
            }
        }
        while(p1 < n1) {
            if(v1[p1] + 1 <= 10) v.push_back(v1[p1] + 1);
            p1++;
        }
        while(p2 < n2) {
            if(v2[p2] + 1 <= 10) v.push_back(v2[p2] + 1);
            p2++;
        }
        return v;
    }

    vector<int> solve(TreeNode* root, int distance, int& ans) {
        if(!root->left && !root->right) return {1};
        vector<int> l, r, cur;
        if(root->left) l = solve(root->left, distance, ans);
        if(root->right) r = solve(root->right, distance, ans);
        for(auto i : l) {
            int mx = distance - i;
            ans += upper_bound(r.begin(), r.end(), mx) - r.begin();
        }
        return merge(l, r);
    }

    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        solve(root, distance, ans);
        return ans;
    }
};
