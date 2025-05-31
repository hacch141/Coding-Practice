// 111. Minimum Depth of Binary Tree

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);

        int lvl = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();
                if(!curr->left && !curr->right) return lvl;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            lvl++;
        }

        return -1;
    }
};

// DFS
class Solution {
public:

    int dfs(TreeNode* root) {
        if(!root) return INT_MAX;
        if(!root->left && !root->right) return 1;
        int l = dfs(root->left);
        int r = dfs(root->right);
        return 1 + min(l, r);
    }

    int minDepth(TreeNode* root) {
        int ans = dfs(root);
        return ans == INT_MAX ? 0 : ans;
    }
};
