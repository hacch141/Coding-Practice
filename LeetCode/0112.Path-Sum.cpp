// 112. Path Sum

class Solution {
public:

    bool helper(TreeNode* root, int sum, int targetSum) {
        if(root) {
            sum += root->val;
            if(!root->left && !root->right && sum==targetSum) {
                return true;
            }
            return helper(root->left,sum,targetSum) || helper(root->right,sum,targetSum);
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,0,targetSum);
    }
};

// ==============================================================


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) {
            return false;
        }
        else if(root->left == NULL && root->right == NULL && root->val == targetSum) {
            return true;
        }
        else {
            return (hasPathSum(root->left,targetSum-root->val)) || (hasPathSum(root->right,targetSum-root->val));
        }
    }
};
