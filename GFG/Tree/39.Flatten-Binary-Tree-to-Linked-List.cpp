// 114. Flatten Binary Tree to Linked List

class Solution {
public:

    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};
// T : O(N)
// S : O(N)
