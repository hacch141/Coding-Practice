// 958. Check Completeness of a Binary Tree

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool isNULL = false;
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left) {
                if(isNULL) return false;
                q.push(curr->left);
            }
            else isNULL = true;
            if(curr->right) {
                if(isNULL) return false;
                q.push(curr->right);
            }
            else isNULL = true;
        }
        return true;
    }
};
