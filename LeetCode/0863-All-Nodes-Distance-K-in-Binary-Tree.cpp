// 863. All Nodes Distance K in Binary Tree

class Solution {
public:
    void find_par(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& par) {
        if(!root) return;
        if(root->left) {
            par[root->left] = root;
            find_par(root->left, par);
        }
        if(root->right) {
            par[root->right] = root;
            find_par(root->right, par);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> par;
        find_par(root, par);

        queue<TreeNode*> q;
        q.push(target);

        set<TreeNode*> vis;
        vis.insert(target);

        int dist = 0;
        vector<int> ans;
        while(!q.empty()) {
            int sz = q.size();
            if (dist == k) {
                while (sz--) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                break;
            }

            while(sz--) {
                auto curr = q.front();
                q.pop();
                if(curr->left && !vis.count(curr->left)) {
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                if(curr->right && !vis.count(curr->right)) {
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                if(par.count(curr) && !vis.count(par[curr])) {
                    q.push(par[curr]);
                    vis.insert(par[curr]);
                }
            }

            dist++;
        }

        return ans;
    }
};
