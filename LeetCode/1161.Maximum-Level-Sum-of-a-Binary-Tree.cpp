// 1161. Maximum Level Sum of a Binary Tree

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans = -1, mx_sum = INT_MIN, lvl = 0;
        while(!q.empty()) {
            int sz = q.size(), sum = 0;
            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            lvl++;

            if(sum > mx_sum) {
                mx_sum = sum;
                ans = lvl;
            }
        }

        return ans;
    }
};
