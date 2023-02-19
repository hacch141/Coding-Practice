// 111. Minimum Depth of Binary Tree

class Solution {
public:
    int minDepth(TreeNode* root) {
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
                if(!curr->left && !curr->right) return lvl;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return 0;
    }
};
