// 958. Check Completeness of a Binary Tree

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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            bool isNull = false;
            for(int i=0; i<cnt; i++) {
                TreeNode* curr = q.front();
                if(curr->left) {
                    q.push(curr->left);
                }
                else {
                    isNull = true;
                    break;
                }
                q.pop();
                if(curr->right) {
                    q.push(curr->right);
                }
                else {
                    isNull = true;
                    break;
                }
            }
            if(isNull) {
                while(!q.empty()) {
                    TreeNode* curr2 = q.front();
                    q.pop();
                    if(curr2->left || curr2->right) return false;
                }
            }
        }
        return true;
    }
};
