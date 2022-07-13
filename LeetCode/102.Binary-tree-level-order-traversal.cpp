// 102. Binary Tree Level Order Traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) {
            return {};
        } 

        vector<vector<int> > ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            vector<int> currLevel;
            int sizeofLevel = size(q);
            
            for(int i=0; i<sizeofLevel; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
                currLevel.push_back(temp->val);
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};
