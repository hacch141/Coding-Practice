// 515. Find Largest Value in Each Tree Row

// BFS
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

// DFS
class Solution {
public:
    void dfs(TreeNode* root, int lvl, vector<int>& ans) {
        if(!root) return;
        if(lvl == ans.size()) ans.push_back(root->val);
        else ans[lvl] = max(ans[lvl], root->val);
        dfs(root->left, lvl + 1, ans);
        dfs(root->right, lvl + 1, ans);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};
