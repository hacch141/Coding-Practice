// 1110. Delete Nodes And Return Forest

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

    void findPar(TreeNode* root, map<int,TreeNode*>& par) {
        if(!root) return;
        if(root->left) {
            par[root->left->val] = root;
            findPar(root->left, par);
        }
        if(root->right) {
            par[root->right->val] = root;
            findPar(root->right, par);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        map<int,TreeNode*> par;
        par[root->val] = NULL;
        findPar(root, par);

        set<TreeNode*> st;
        st.insert(root);
        for(auto u : to_delete) {
            TreeNode* cur;
            if(par[u] == NULL) {
                cur = root;
            }
            else {
                if(par[u]->right && par[u]->right->val == u) {
                    cur = par[u]->right;
                    par[u]->right = NULL;
                }
                else {
                    cur = par[u]->left;
                    par[u]->left = NULL;
                }
            }
            if(st.count(cur)) st.erase(st.find(cur));
            if(cur->left) st.insert(cur->left);
            if(cur->right) st.insert(cur->right);
        }

        vector<TreeNode*> ans;
        for(auto node : st) {
            ans.push_back(node);
        }

        return ans;
    }
};
