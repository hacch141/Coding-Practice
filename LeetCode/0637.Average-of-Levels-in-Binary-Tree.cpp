// 637. Average of Levels in Binary Tree

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        ans.push_back(root->val);
        double lev_sum = 0;

        while(!q.empty()) {
            int len = q.size();
            for(int i=0; i<len; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) {
                    q.push(curr->left);
                    lev_sum += curr->left->val;
                }
                if(curr->right) {
                    q.push(curr->right);
                    lev_sum += curr->right->val;
                }
            }
            if(q.size()) ans.push_back(lev_sum/q.size());
            lev_sum = 0;
        }
        return ans;
    }
};
