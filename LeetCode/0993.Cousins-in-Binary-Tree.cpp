// 993. Cousins in Binary Tree

// BFS
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int l1, l2, p1, p2;
        if(root->val==x || root->val==y) return false;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int n = q.size();
            level++;
            for(int i=0; i<n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) {
                    q.push(curr->left);
                    if(curr->left->val == x) {
                        l1 = level;
                        p1 = curr->val;
                    }
                    else if(curr->left->val == y) {
                        l2 = level;
                        p2 = curr->val;
                    }
                }
                if(curr->right) {
                    q.push(curr->right);
                    if(curr->right->val == x) {
                        l1 = level;
                        p1 = curr->val;
                    }
                    else if(curr->right->val == y) {
                        l2 = level;
                        p2 = curr->val;
                    }
                }
            }
        }
        return l1==l2 && p1!=p2;
    }
};

// DFS
class Solution {
public:

    void dfs(int level, TreeNode* root, int prev, int& x, int& y, int& l1, int& p1, int& l2, int& p2) {
        if(!root) return;
        if(root->val==x ) {
            l1 = level;
            p1 = prev;
        }
        else if(root->val==y) {
            l2 = level;
            p2 = prev;
        }
        level++;
        dfs(level,root->left,root->val,x,y,l1,p1,l2,p2);
        dfs(level,root->right,root->val,x,y,l1,p1,l2,p2);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int l1, l2, p1, p2;
        if(root->val==x || root->val==y) return false;
        dfs(0,root,-1,x,y,l1,p1,l2,p2);
        return l1==l2 && p1!=p2;
    }
};
