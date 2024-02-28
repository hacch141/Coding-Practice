// 513. Find Bottom Left Tree Value

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = -1;
        while(!q.empty()) {
            int len = q.size();
            bool f = true;
            while(len--) {
                TreeNode* node = q.front();
                q.pop();
                if(f) {
                    ans = node->val;
                    f = false;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};
