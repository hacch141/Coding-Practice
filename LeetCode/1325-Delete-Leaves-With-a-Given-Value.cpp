// 1325. Delete Leaves With a Given Value

class Solution {
public:
    TreeNode* dfs(TreeNode* root, int target) {
        if(!root) return NULL;

        root->left = dfs(root->left, target);
        root->right = dfs(root->right, target);

        if(!root->left && !root->right && root->val == target) return NULL;

        return root;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root,target);
    }
};
