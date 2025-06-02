// 513. Find Bottom Left Tree Value

// BFS
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while(!q.empty()) {
            int sz = q.size();
            ans = q.front()->val;
            while(sz--) {
                auto curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return ans;
    }
};

// DFS
class Solution {
public:
    void dfs(TreeNode* root, int depth, int& mx_depth, int& ans) {
        if(!root) return;
        if(depth > mx_depth) {
            ans = root->val;
            mx_depth = depth;
        }
        dfs(root->left, depth + 1, mx_depth, ans);
        dfs(root->right, depth + 1, mx_depth, ans);
    }

    int findBottomLeftValue(TreeNode* root) {
        int ans, mx_depth = 0;
        dfs(root, 1, mx_depth, ans);
        return ans;
    }
};
