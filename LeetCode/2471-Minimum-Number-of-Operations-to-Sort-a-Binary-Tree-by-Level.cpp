// 2471. Minimum Number of Operations to Sort a Binary Tree by Level

class Solution {
public:

    int get_cnt(vector<int>& v) {
        int n = v.size(), cnt = 0;

        vector<int> sorted_v = v;
        sort(sorted_v.begin(), sorted_v.end());

        map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[v[i]] = i;
        }

        for(int i = 0; i < n; i++) {
            if(v[i] != sorted_v[i]) {
                int ind1 = i, ind2 = mp[sorted_v[i]];
                swap(v[ind1], v[ind2]);
                mp[v[ind1]] = ind1;
                mp[v[ind2]] = ind2;
                cnt++;
            }
        }
        return cnt;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            vector<int> v;
            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans += get_cnt(v);
        }
        return ans;
    }
};
