// 108. Convert Sorted Array to Binary Search Tree

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

    TreeNode* binary(int start, int end, vector<int>& nums) {
        if(start>end) return NULL;
        int mid = (end-start)/2 + start;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = binary(start,mid-1,nums);
        root->right = binary(mid+1,end,nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = binary(0,n-1,nums);
        return root;
    }
};
