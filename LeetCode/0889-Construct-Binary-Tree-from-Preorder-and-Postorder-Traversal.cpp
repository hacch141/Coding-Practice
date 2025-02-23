// 889. Construct Binary Tree from Preorder and Postorder Traversal

class Solution {
public:
    TreeNode* rec(int l, int r, int& pre_ind, vector<int>& preorder, vector<int>& postorder, vector<int>& get_ind) {
        if (l > r || pre_ind >= preorder.size()) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[pre_ind]);
        pre_ind++;

        if (l == r) return root;

        int post_ind = get_ind[preorder[pre_ind]];
        
        root->left = rec(l, post_ind, pre_ind, preorder, postorder, get_ind);
        root->right = rec(post_ind + 1, r - 1, pre_ind, preorder, postorder, get_ind);
        
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size(), pre_ind = 0;
        vector<int> get_ind(31, -1);
        for (int i = 0; i < n; i++) {
            get_ind[postorder[i]] = i;
        }
        return rec(0, n - 1, pre_ind, preorder, postorder, get_ind);
    }
};
