// 958. Check Completeness of a Binary Tree

// BFS
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool stop = false;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto curr = q.front();
                q.pop();
                if(stop && curr->left) return false;
                if(!stop && curr->left) {
                    q.push(curr->left);
                }
                else {
                    stop = true;
                }
                if(stop && curr->right) return false;
                if(!stop && curr->right) {
                    q.push(curr->right);
                } 
                else {
                    stop = true;
                }
            }
        }
        return true;
    }
};

// DFS
class Solution {
public:
    int get_count(TreeNode* root) {
        if(!root) return 0;
        return 1 + get_count(root->left) + get_count(root->right);
    }

    bool dfs(int ind, int& total_nodes, TreeNode* root) {
        if(!root) return true;
        if(ind >= total_nodes) return false;
        return dfs(2 * ind + 1, total_nodes, root->left) && dfs(2 * ind + 2, total_nodes, root->right);
    }

    bool isCompleteTree(TreeNode* root) {
        int total_nodes = get_count(root);
        int ind = 0;
        return dfs(ind, total_nodes, root);
    }
};
