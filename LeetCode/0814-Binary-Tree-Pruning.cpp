// 814. Binary Tree Pruning

class Solution {
public:
    TreeNode* dfs(TreeNode* root) {
        if(!root) return root;
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        if(!root->left && !root->right && root->val != 1) return NULL;
        return root;
    }

    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root);
    }
};
// TC : O(N)

// ========================================================

class Solution {
public:
	//This is called for all node and hence Time : O(n^2)
    bool checkOne(TreeNode* root) {
        if(!root)
            return false;
        
        if(root->val == 1)
            return true;
        
        return checkOne(root->left) || checkOne(root->right);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL;
        
        pruneTree(root->left);
        pruneTree(root->right);
        
        if(!checkOne(root->left))  root->left = NULL;
        if(!checkOne(root->right)) root->right = NULL;
        
        
        if(!root->left && !root->right && root->val == 0)
            return NULL;
        return root;
    }
};
// TC : O(N^2)
