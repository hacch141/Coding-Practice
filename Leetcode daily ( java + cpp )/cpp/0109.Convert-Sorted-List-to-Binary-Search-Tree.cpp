// 109. Convert Sorted List to Binary Search Tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    TreeNode* binary(int start, int end, vector<int>& v) {
        if(start>end) return NULL;
        int mid = (end-start)/2 + start;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = binary(start,mid-1,v);
        root->right = binary(mid+1,end,v);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        TreeNode* root = binary(0,n-1,v);
        return root;
    }
};
