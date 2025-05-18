// 623. Add One Row to Tree

// DFS
class Solution {
public:
    void dfs(TreeNode* root, int val, int depth) {
        if(!root) return;
        if(depth == 2) {
            TreeNode* new_node_l = new TreeNode(val);
            new_node_l->left = root->left;
            root->left = new_node_l;
            TreeNode* new_node_r = new TreeNode(val);
            new_node_r->right = root->right;
            root->right = new_node_r;
            return;
        }
        dfs(root->left, val, depth - 1);
        dfs(root->right, val, depth - 1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            return new_root;
        }
        
        dfs(root, val, depth);
        return root;
    }
};


// BFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* new_root = new TreeNode(val);
            new_root->left = root;
            return new_root;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1;
        while(!q.empty()) {
            if(lvl == depth - 1) break;
            int sz = q.size();
            while(sz--) {
                auto curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            lvl++;
        }

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            TreeNode* new_node_l = new TreeNode(val);
            new_node_l->left = curr->left;
            curr->left = new_node_l;
            TreeNode* new_node_r = new TreeNode(val);
            new_node_r->right = curr->right;
            curr->right = new_node_r;
        }

        return root;
    }
};
