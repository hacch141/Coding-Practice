// 2415. Reverse Odd Levels of Binary Tree

// BFS
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int lvl = 0;
        while(!q.empty()) {
            int sz = q.size();
            vector<TreeNode*> nodes;

            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();

                if(lvl & 1) nodes.push_back(curr);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(lvl & 1) {
                int l = 0, r = nodes.size() - 1;
                while(l < r) {
                    swap(nodes[l]->val, nodes[r]->val);
                    l++;
                    r--;
                }
            }

            lvl++;
        }

        return root;
    }
};

// DFS
class Solution {
public:
    void dfs(TreeNode* root1, TreeNode* root2, int lvl) {
        if(!root1 && !root2) return;
        if(lvl & 1) swap(root1->val, root2->val);

        dfs(root1->left, root2->right, lvl + 1);
        dfs(root1->right, root2->left, lvl + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 1);
        return root;
    }
};
