// 199. Binary Tree Right Side View

// BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                if(i == sz - 1) ans.push_back(curr->val);
            }
        }
        return ans;
    }
};

// DFS
class Solution {
public:
    void dfs(int lvl, TreeNode* root, vector<int>& ans) {
        if(!root) return;
        if(lvl == ans.size()) ans.push_back(root->val);
        else ans[lvl] = root->val;
        dfs(lvl + 1, root->left, ans);
        dfs(lvl + 1, root->right, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(0, root, ans);
        return ans;
    }
};
