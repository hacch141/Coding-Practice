// 2196. Create Binary Tree From Descriptions

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, vector<pair<int,int>>> mp;
        set<int> nodes;
        for(auto i : descriptions) {
            mp[i[0]].push_back({i[1], i[2]});
            nodes.insert(i[1]);
        }

        int par;
        for(auto i : descriptions) {
            if(!nodes.count(i[0])) {
                par = i[0];
                break;
            }
        }

        TreeNode* root = new TreeNode(par);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();
                int val = curr->val;
                for(auto i : mp[val]) {
                    int child = i.first;
                    bool isLeft = i.second;
                    if(isLeft) {
                        curr->left = new TreeNode(child);
                        q.push(curr->left);
                    }
                    else {
                        curr->right = new TreeNode(child);
                        q.push(curr->right);
                    }
                }
            }
        }

        return root;
    }
};
