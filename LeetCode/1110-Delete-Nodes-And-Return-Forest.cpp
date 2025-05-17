// 1110. Delete Nodes And Return Forest

// DFS
class Solution {
public:
    TreeNode* dfs(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& ans) {
        if(!root) return NULL;
        root->left = dfs(root->left, st, ans);
        root->right = dfs(root->right, st, ans);
        if(st.count(root->val)) {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return NULL;
        }
        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        for(auto i : to_delete) st.insert(i);

        vector<TreeNode*> ans;
        if(!st.count(root->val)) ans.push_back(root);

        dfs(root, st, ans);
        return ans;
    }
};

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
