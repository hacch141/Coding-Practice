// 1609. Even Odd Tree

// BFS
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int lvl = 0;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> v;
            while(sz--) {
                auto curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }

            int n = v.size();
            if(lvl % 2 == 0) {
                for(int i = 0; i < n; i++) {
                    if(v[i] % 2 == 0 || (i + 1 < n && v[i] >= v[i + 1])) return false;
                }
            }
            else {
                for(int i = n - 1; i >= 0; i--) {
                    if(v[i] % 2 != 0 || (i - 1 >= 0 && v[i] >= v[i - 1])) return false;
                }
            }
            lvl++;
        }
        return true;
    }
};
