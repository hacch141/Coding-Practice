// 515. Find Largest Value in Each Tree Row

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            int mx = INT_MIN;
            while(sz--) {
                auto curr = q.front();
                q.pop();
                mx = max(mx, curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(mx);
        }

        return ans;
    }
};
