// 2415. Reverse Odd Levels of Binary Tree

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int lvl = 0;
        while(!q.empty()) {
            int sz = q.size();

            vector<int> val;
            vector<TreeNode*> nodes;

            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();

                if(lvl & 1) {
                    val.push_back(curr->val);
                    nodes.push_back(curr);
                }

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(lvl & 1) {
                reverse(val.begin(), val.end());
                for(int i = 0; i < nodes.size(); i++) {
                    nodes[i]->val = val[i];
                }
            }

            lvl++;
        }

        return root;
    }
};
