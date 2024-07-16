// 2096. Step-By-Step Directions From a Binary Tree Node to Another

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

    TreeNode* getLCA(TreeNode* root, int u, int v) {
        if(!root) return NULL;
        if(root->val == u || root->val == v) return root;
        TreeNode* l = getLCA(root->left, u, v);
        TreeNode* r = getLCA(root->right, u, v);
        if(l && r) return root;
        if(l) return l;
        if(r) return r;
        return NULL;
    }

    void getPath(TreeNode* root, int val, string& cur, string& ans) {
        if(!root || ans.length() > 0) return;
        if(root->val == val) {
            ans = cur;
            return;
        }

        cur.push_back('L');
        getPath(root->left, val, cur, ans);
        cur.pop_back();

        cur.push_back('R');
        getPath(root->right, val, cur, ans);
        cur.pop_back();
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = getLCA(root, startValue, destValue);
        string cur, l, r;
        getPath(lca, startValue, cur, l);
        getPath(lca, destValue, cur, r);
        string path(l.length(), 'U');
        path += r;
        return path;
    }
};
