// 129. Sum Root to Leaf Numbers

class Solution {
public:

    void helper(TreeNode* root, int curr, int& sum) {
        if(root) {
            curr = (curr*10) + root->val;
            if(!root->left && !root->right) {
                sum += curr;
            }
        } else return;
        helper(root->left,curr,sum);
        helper(root->right,curr,sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int curr = 0;
        helper(root,curr,sum);
        return sum;
    }
};
