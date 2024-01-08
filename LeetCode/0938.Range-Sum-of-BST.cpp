// 938. Range Sum of BST

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        while(root) {
            if(root->left) {
                TreeNode* newRoot = root->left;
                TreeNode* prev = root->left;
                while(prev->right) prev = prev->right;
                prev->right = root;
                root->left = NULL;
                root = newRoot;
            }
            else {
                if(low <= root->val && root->val <= high) ans += root->val;
                root = root->right;
            }
        }

        return ans;
    }
};


class Solution {
public:
    int sum = 0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root) {
            rangeSumBST(root->left, low, high);
            if(root->val>=low && root->val<=high) {
                sum += root->val;
            }
            rangeSumBST(root->right, low, high);
        }
        else {
            return 0;
        }
        return sum;
    }
};
