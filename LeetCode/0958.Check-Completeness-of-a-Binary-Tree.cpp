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

// ======================================================================


class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            bool isNull = false;
            for(int i=0; i<cnt; i++) {
                TreeNode* curr = q.front();
                if(curr->left) {
                    q.push(curr->left);
                }
                else {
                    isNull = true;
                    break;
                }
                q.pop();
                if(curr->right) {
                    q.push(curr->right);
                }
                else {
                    isNull = true;
                    break;
                }
            }
            if(isNull) {
                while(!q.empty()) {
                    TreeNode* curr2 = q.front();
                    q.pop();
                    if(curr2->left || curr2->right) return false;
                }
            }
        }
        return true;
    }
};
