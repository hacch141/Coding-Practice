// 113. Path Sum II

class Solution {
public:

    void helper(TreeNode* root, int sum, int& targetSum, vector<int>& curr, vector<vector<int>>& ans) {
        if(root) {
            sum += root->val;
            curr.push_back(root->val);
            if(sum==targetSum && !root->left && !root->right) {
                ans.push_back(curr);
                return;
            }
            if(root->left) {
                helper(root->left,sum,targetSum,curr,ans);
                curr.pop_back();
            }
            if(root->right) {
                helper(root->right,sum,targetSum,curr,ans);
                curr.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(root,0,targetSum,curr,ans);
        return ans;
    }
};
