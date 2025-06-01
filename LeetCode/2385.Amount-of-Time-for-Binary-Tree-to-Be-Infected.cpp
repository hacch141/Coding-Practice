// 2385. Amount of Time for Binary Tree to Be Infected

class Solution {
public:
    void find_par(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& par, int& start, TreeNode*& st) {
        if(!root) return;
        if(root->val == start) st = root;
        if(root->left) {
            par[root->left] = root;
            find_par(root->left, par, start, st);
        }
        if(root->right) {
            par[root->right] = root;
            find_par(root->right, par, start, st);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> par;
        TreeNode* st;
        find_par(root, par, start, st);

        queue<TreeNode*> q;
        q.push(st);

        set<int> vis;
        vis.insert(start);

        int min = -1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto curr = q.front();
                q.pop();
                if(curr->left && !vis.count(curr->left->val)) {
                    q.push(curr->left);
                    vis.insert(curr->left->val);
                }
                if(curr->right && !vis.count(curr->right->val)) {
                    q.push(curr->right);
                    vis.insert(curr->right->val);
                }
                if(par.count(curr) && !vis.count(par[curr]->val)) {
                    q.push(par[curr]);
                    vis.insert(par[curr]->val);
                }
            }
            min++;
        }

        return min;
    }
};
