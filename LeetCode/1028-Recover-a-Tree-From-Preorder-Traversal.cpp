// 1028. Recover a Tree From Preorder Traversal

class Solution {
public:
    TreeNode* rec(int l, int r, vector<pair<int,int>>& v) {
        if(l > r) return nullptr;
        TreeNode* root = new TreeNode(v[l].first);
        if(l + 1 < v.size() && v[l + 1].second == v[l].second + 1) {
            int mid = l + 2;
            while(mid <= r && v[l + 1].second != v[mid].second) {
                mid++;
            }
            root->left = rec(l + 1, mid - 1, v);
            root->right = rec(mid, r, v);
        }
        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int,int>> v;
        int ind = 0;
        while(ind < traversal.length()) {
            int lvl = 0;
            while(ind < traversal.length() && traversal[ind] == '-') {
                lvl++;
                ind++;
            }
            int num = 0;
            while(ind < traversal.length() && traversal[ind] >= '0' && traversal[ind] <= '9') {
                num = num * 10 + (traversal[ind] - '0');
                ind++;
            }
            v.push_back({num, lvl});
        }
        int n = v.size();
        return rec(0, n - 1, v);
    }
};
