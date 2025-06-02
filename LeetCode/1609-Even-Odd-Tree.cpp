// 1609. Even Odd Tree

// BFS
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int lvl = 0;
        while(!q.empty()) {
            int sz = q.size();
            int prev = lvl % 2 == 0 ? INT_MIN : INT_MAX;
            while(sz--) {
                auto curr = q.front();
                q.pop();

                if(lvl % 2 == 0 && (curr->val % 2 == 0 || curr->val <= prev)) return false;
                if(lvl % 2 != 0 && (curr->val % 2 != 0 || curr->val >= prev)) return false;

                prev = curr->val;
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
            lvl++;
        }
        return true;
    }
};

// DFS
class Solution {
public:
    bool dfs(TreeNode* root, int lvl, vector<int>& prev) {
        if(!root) return true;

        if(lvl % 2 == root->val % 2) return false;

        if(lvl >= prev.size()) {
            prev.push_back(-1);
        }

        if(prev[lvl] != -1) {
            if(lvl % 2 == 0 && root->val <= prev[lvl]) return false;
            if(lvl % 2 != 0 && root->val >= prev[lvl]) return false;
        }

        prev[lvl] = root->val;
        return dfs(root->left, lvl + 1, prev) && dfs(root->right, lvl + 1, prev);
    }

    bool isEvenOddTree(TreeNode* root) {
        vector<int> prev;
        return dfs(root, 0, prev);
    }
};
