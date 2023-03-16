// 257. Binary Tree Paths

class Solution {
public:

    void helper(TreeNode* root, string str, vector<string>& ans) {
        if(root) {
            str = str + "->" + to_string(root->val);
            if(!root->left && !root->right) {
                str.erase(0,2);
                ans.push_back(str);
            }
            if(root->left) helper(root->left,str,ans);
            if(root->right) helper(root->right,str,ans);
        }
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root,"",ans);
        return ans;
    }
};
