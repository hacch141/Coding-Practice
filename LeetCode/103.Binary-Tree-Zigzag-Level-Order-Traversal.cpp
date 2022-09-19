// 103. Binary Tree Zigzag Level Order Traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        
        vector<vector<int>> ans;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        
        while(s1.empty()==false  || s2.empty()==false) {
            vector<int> v;
            if(s1.empty() == false) {
                while(s1.empty() == false) {
                    TreeNode* curr = s1.top();
                    s1.pop();
                    if(curr->left) {
                        s2.push(curr->left);    
                    }
                    if(curr->right) {
                        s2.push(curr->right);
                    }
                    v.push_back(curr->val);
                }
            }
            else if(s2.empty() == false) {
                while(s2.empty() == false) {
                    TreeNode* curr = s2.top();
                    s2.pop();
                    if(curr->right) {
                        s1.push(curr->right);
                    }
                    if(curr->left) {
                        s1.push(curr->left);
                    }
                    v.push_back(curr->val);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};
    
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {  // 2nd Method
//         if(root == NULL) {
//             return {};
//         }
        
//         vector<vector<int>> ans;
//         queue<TreeNode*> q;
//         stack<int> st;
//         q.push(root);
//         bool reverse = false;
        
//         while(q.empty() == false) {
//             int cnt = q.size();
//             vector<int> v;
//             for(int i=0; i<cnt; i++) {
//                 TreeNode* curr = q.front();
//                 q.pop();
//                 if(reverse) {
//                     st.push(curr->val);
//                 }
//                 else {
//                     v.push_back(curr->val);
//                 }
//                 if(curr->left) {
//                     q.push(curr->left);
//                 }
//                 if(curr->right) {
//                     q.push(curr->right);
//                 }
//             }
//             if(reverse) {
//                 while(st.empty() == false) {
//                     v.push_back(st.top());
//                     st.pop();
//                 }
//             }
//             ans.push_back(v);
//             reverse = !reverse;
//         }
//         return ans;
//     }
};
