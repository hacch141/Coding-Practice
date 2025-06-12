// 1028. Recover a Tree From Preorder Traversal

class Solution {
public:
    TreeNode* dfs(int lvl, int& ind, int& n, string& s) {
        if (ind >= n) return NULL;

        int cnt = 0;
        // Count dashes to determine level
        while (ind < n && s[ind] == '-') {
            cnt++;
            ind++;
        }

        // If level doesn't match, backtrack
        if (cnt != lvl) {
            ind -= cnt;  // backtrack to allow parent to parse
            return NULL;
        }

        // Parse number (can be multi-digit)
        int num = 0;
        while (ind < n && isdigit(s[ind])) {
            num = num * 10 + (s[ind] - '0');
            ind++;
        }

        TreeNode* root = new TreeNode(num);
        root->left = dfs(lvl + 1, ind, n, s);
        root->right = dfs(lvl + 1, ind, n, s);
        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int ind = 0;
        return dfs(0, ind, n, traversal);
    }
};


// 
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
