// 94. Binary Tree Inorder Traversal

class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

// Morris Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        TreeNode* st = NULL;
        while(curr) {
            if(curr->left) {
                TreeNode* l = curr->left;
                while(l->right) l = l->right;
                l->right = curr;

                TreeNode* tmp = curr;
                curr = curr->left;
                tmp->left = NULL;
            }
            else {
                if(!st) st = curr;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};
