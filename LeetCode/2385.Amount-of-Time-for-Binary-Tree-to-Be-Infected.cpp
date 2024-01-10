// 2385. Amount of Time for Binary Tree to Be Infected

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void findParents(TreeNode*& root, unordered_map<int,TreeNode*>& mp, int& start, TreeNode*& st) {
        if(!root) return;
        if(root->val == start) {
            st = root;
        }
        if(root->left) {
            mp[root->left->val] = root;
            findParents(root->left, mp, start, st);
        }
        if(root->right) {
            mp[root->right->val] = root;
            findParents(root->right, mp, start, st);
        }
    }

    int bfs(TreeNode*& st, unordered_map<int,TreeNode*>& mp, unordered_map<int,bool>& vis) {
        queue<TreeNode*> q;
        q.push(st);
        vis[st->val] = true;
        int time = -1;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left->val]) {
                    q.push(curr->left);
                    vis[curr->left->val] = true;
                }
                if(curr->right && !vis[curr->right->val]) {
                    q.push(curr->right);
                    vis[curr->right->val] = true;
                }
                TreeNode* par = mp[curr->val];
                if(par && !vis[par->val]) {
                    q.push(par);
                    vis[par->val] = true;
                }
            }
            time++;
        }
        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode* st;
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,bool> vis;
        findParents(root, mp, start, st);
        return bfs(st, mp, vis);
    }
};
