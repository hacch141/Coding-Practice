// 2415. Reverse Odd Levels of Binary Tree

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int lvl = 0;
        while(!q.empty()) {
            int sz = q.size();
            vector<TreeNode*> nodes;

            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();

                if(lvl & 1) nodes.push_back(curr);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(lvl & 1) {
                int l = 0, r = nodes.size() - 1;
                while(l < r) {
                    swap(nodes[l]->val, nodes[r]->val);
                    l++;
                    r--;
                }
            }

            lvl++;
        }

        return root;
    }
};
