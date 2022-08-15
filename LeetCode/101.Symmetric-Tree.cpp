// 101. Symmetric Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        return helper(root->left,root->right);
    }
    
    bool helper(TreeNode* n1, TreeNode* n2) {
        if(n1 == NULL && n2 == NULL) {
            return true;
        }
        else if(n1 == NULL || n2 == NULL) {
            return false;
        }
        else if(n1->val != n2->val) {
            return false;
        }
        return helper(n1->left,n2->right) && helper(n1->right,n2->left);
    }
};
