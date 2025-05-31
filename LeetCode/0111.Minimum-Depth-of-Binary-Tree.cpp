// 111. Minimum Depth of Binary Tree

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);

        int lvl = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();
                if(!curr->left && !curr->right) return lvl;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            lvl++;
        }

        return -1;
    }
};
