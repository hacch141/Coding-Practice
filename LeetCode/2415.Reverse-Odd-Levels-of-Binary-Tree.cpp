// 2415. Reverse Odd Levels of Binary Tree

class Solution {
public:

    void rev_q(queue<TreeNode*>& q, vector<int>& temp) {
        reverse(temp.begin(),temp.end());
        int len = q.size();
        for(int i=0; i<len; i++) {
            TreeNode* curr = q.front();
            q.pop();
            curr->val = temp[i];
            q.push(curr);
        }
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        bool reverse = true;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;

        while(!q.empty()) {
            int len = q.size();
            for(int i=0; i<len; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) {
                    q.push(curr->left);
                    temp.push_back(curr->left->val);
                }
                if(curr->right) {
                    q.push(curr->right);
                    temp.push_back(curr->right->val);
                }
            }
            if(reverse) {
                rev_q(q,temp);
            }
            reverse = !reverse;
            temp.clear();
        }
        return root;
    }
};
