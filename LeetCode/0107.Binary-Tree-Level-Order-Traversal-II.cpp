// 107. Binary Tree Level Order Traversal II

// DFS
// 107. Binary Tree Level Order Traversal II

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        ans.push_back({root->val});
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int len = q.size();
            for(int i=0; i<len; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) {
                    q.push(curr->left);
                    temp.push_back(curr->left->val);
                }
                if(curr->right) {
                    q.push(curr->right);
                    temp.push_back(curr->right->val);
                }
            }
            if(temp.size()>0) ans.push_back(temp);
            temp.clear();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



// BFS
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        ans.push_back({root->val});
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int len = q.size();
            for(int i=0; i<len; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) {
                    q.push(curr->left);
                    temp.push_back(curr->left->val);
                }
                if(curr->right) {
                    q.push(curr->right);
                    temp.push_back(curr->right->val);
                }
            }
            if(temp.size()>0) ans.push_back(temp);
            temp.clear();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
