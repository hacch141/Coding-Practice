// 515. Find Largest Value in Each Tree Row

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        vector<int> ans;
        while(!q.empty()) {
            int sz = q.size(), mx = INT_MIN;
            while(sz--) {
                auto curr = q.front();
                mx = max(mx, curr->val);
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
