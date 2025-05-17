// 958. Check Completeness of a Binary Tree

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
                if(!curr) {
                    stop = true;
                }
                else {
                    if(stop) return false;
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }
        return true;
    }
};
