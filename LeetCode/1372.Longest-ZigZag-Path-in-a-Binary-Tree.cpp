// 1372. Longest ZigZag Path in a Binary Tree

class Solution {
public:

    vector<int> helper(TreeNode* root) {
        if(!root) return {-1,-1,-1};

        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);

        int res = max(1+max(left[1],right[0]), max(left[2],right[2]));

        return {1+left[1],1+right[0],res};
    }

    int longestZigZag(TreeNode* root) {
        return helper(root)[2];
    }
};


