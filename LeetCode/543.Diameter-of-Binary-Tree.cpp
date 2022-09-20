// 543. Diameter of Binary Tree

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
    
    int ans = 0;
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        ans = max(ans,1+lh+rh);
        return 1+max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans-1;
    }
    
//     int height(TreeNode* root) {   // 2nd Method
//         if(root == NULL) {
//             return 0;
//         }
//         return 1+max(height(root->left),height(root->right));
//     }
    
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root == NULL) {
//             return 0;
//         }
//         int d1 = height(root->left)+height(root->right);
//         int d2 = diameterOfBinaryTree(root->left);
//         int d3 = diameterOfBinaryTree(root->right);
//         return max(d1,max(d2,d3));
//     }
};
