// 1161. Maximum Level Sum of a Binary Tree

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        int ans = -1;
        int maxi = INT_MIN;
        while(!q.empty()) {
            int sum = 0;
            int n = q.size();
            for(int i=0; i<n; i++) {
                TreeNode* curr = q.front();
                sum += curr->val;
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
            if(sum > maxi) {
                maxi = sum;
                ans = level;
            }
        }
        return ans;
    }
};
