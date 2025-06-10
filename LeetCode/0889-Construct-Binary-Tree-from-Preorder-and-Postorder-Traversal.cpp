// 889. Construct Binary Tree from Preorder and Postorder Traversal

class Solution {
public:
    TreeNode* dfs(int l, int r, int& pre_ind, int& n, vector<int>& preorder, vector<int>& postorder, unordered_map<int,int>& mp) {
        if(l > r || pre_ind >= n) return NULL;

        TreeNode* root = new TreeNode(preorder[pre_ind]);
        pre_ind++;

        if(pre_ind >= n || l == r) return root;
        int mid_ind = mp[preorder[pre_ind]];

        root->left = dfs(l, mid_ind, pre_ind, n, preorder, postorder, mp);
        root->right = dfs(mid_ind + 1, r - 1, pre_ind, n, preorder, postorder, mp);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size(), pre_ind = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) mp[postorder[i]] = i;
        return dfs(0, n - 1, pre_ind, n, preorder, postorder, mp);
    }
};
