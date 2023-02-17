// 783. Minimum Distance Between BST Nodes

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int mini = INT_MAX;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            int currval = curr->val;
            if(curr->left) {
                TreeNode* temp1 = curr->left;
                while(temp1->right!=NULL) {
                    temp1 = temp1->right;
                }
                mini = min(mini,currval-temp1->val);
            }
            if(curr->right) {
                TreeNode* temp2 = curr->right;
                while(temp2->left!=NULL) {
                    temp2 = temp2->left;
                }
                mini = min(mini,temp2->val-currval);
            }
        }
        return mini;
    }
};
