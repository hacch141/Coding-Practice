// 129. Sum Root to Leaf Numbers

class Solution {
public:

    int helper(TreeNode* root, int sum) {
        if(root) {
            sum = sum*10 + root->val;
            if(!root->left && !root->right) return sum;
            return helper(root->left,sum) + helper(root->right,sum);
        } 
        return 0;
    }

    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
};

// ==========================================================================



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
