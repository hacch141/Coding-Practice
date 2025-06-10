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

//Approach-2 (using map to optimise)
//T.C : O(n)
//S.C : O(n) using map of size n (you can also include n for System Stack used for Recursion)
class Solution {
public:
    TreeNode* solve(int prestart, int poststart, int preend, vector<int>& preorder, vector<int>& postorder,
                    unordered_map<int, int>& mp) {
        if(prestart > preend) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);
        if(prestart == preend) {
            return root;
        }
        int nextNode = preorder[prestart+1]; //root of left subtree

        int j = mp[nextNode];

        int num = j - poststart + 1;

        root->left = solve(prestart+1, poststart, prestart+num, preorder, postorder, mp);
        root->right = solve(prestart+num+1, j+1, preend, preorder, postorder, mp);

        return root;
    }


    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[postorder[i]] = i;
        }
        return solve(0, 0, n-1, preorder, postorder, mp);
    }
};
