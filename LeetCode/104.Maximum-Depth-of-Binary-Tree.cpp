// 104. Maximum Depth of Binary Tree

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        if(left_depth > right_depth) {
            return 1+left_depth;
        }
        return 1+right_depth;
    }
};


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int lvl = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int len = q.size();
            lvl++;
            for(int i=0; i<len; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return lvl;
    }
};
