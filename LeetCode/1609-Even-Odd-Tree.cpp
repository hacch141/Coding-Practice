// 1609. Even Odd Tree

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        while(!q.empty()) {
            int len = q.size();
            TreeNode* prev = q.front();
            q.pop();
            if(prev->left) q.push(prev->left);
            if(prev->right) q.push(prev->right);
            if((lvl % 2 == 0 && prev->val % 2 == 0) || (lvl % 2 == 1 && prev->val % 2 == 1)) return false;
            for(int i = 1; i < len; i++) {
                TreeNode* cur = q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                q.pop();
                if(lvl % 2 == 0) {
                    if(cur->val <= prev->val || cur->val % 2 == 0) return false;
                }
                else {
                    if(cur->val >= prev->val || cur->val % 2 == 1) return false;
                }
                prev = cur;
            }
            lvl++;
        }
        return true;
    }
};
