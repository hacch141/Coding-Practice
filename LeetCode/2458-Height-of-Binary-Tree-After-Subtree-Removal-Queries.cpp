// 2458. Height of Binary Tree After Subtree Removal Queries

class Solution {
public:
    int level[100001];
    int height[100001];
    int mx_h[100001];
    int sec_mx_h[100001];

    int dfs(int lvl, TreeNode* root) {
        if(!root) return 0;

        level[root->val] = lvl;

        int l = dfs(lvl + 1, root->left);
        int r = dfs(lvl + 1, root->right);

        int curr = 1 + max(l, r);
        height[root->val] = curr;
        if(curr >= mx_h[lvl]) {
            sec_mx_h[lvl] = mx_h[lvl];
            mx_h[lvl] = curr;
        }
        else if(curr > sec_mx_h[lvl]) {
            sec_mx_h[lvl] = curr;
        }

        return curr;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(0, root);

        vector<int> ans;
        for(auto q : queries) {
            int lvl = level[q];
            int h = lvl + (height[q] != mx_h[lvl] ? mx_h[lvl] : sec_mx_h[lvl]) - 1;
            ans.push_back(h);
        }

        return ans;
    }
};

// 
class Solution {
public:
    // store max_height and second_max_height achived by by each lvl
    int get_height(int lvl, TreeNode* root, unordered_map<int,pair<int,int>>& mp) {
        if(!root) return -1;

        int l = get_height(lvl + 1, root->left, mp);
        int r = get_height(lvl + 1, root->right, mp);

        int curr = 1 + max(l, r);
        if(mp.find(lvl) == mp.end()) {
            mp[lvl] = {curr, -1};
        }
        else {
            if(curr >= mp[lvl].first) {
                mp[lvl].second = mp[lvl].first;
                mp[lvl].first = curr;
            }
            else if(curr > mp[lvl].second) {
                mp[lvl].second = curr;
            }
        }

        return curr;
    }

    int dfs(int lvl, TreeNode* root, unordered_map<int,int>& mpp, unordered_map<int,pair<int,int>>& mp) {
        if(!root) return -1;

        int l = dfs(lvl + 1, root->left, mpp, mp);
        int r = dfs(lvl + 1, root->right, mpp, mp);

        int curr = 1 + max(l, r);
        if(mp[lvl].first != curr) {
            mpp[root->val] = lvl + mp[lvl].first;
        }
        else if(mp[lvl].second != -1) {
            mpp[root->val] = lvl + mp[lvl].second;
        }
        else {
            mpp[root->val] = lvl - 1;
        }

        return curr;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // map<max_height, second_max_height>
        unordered_map<int,pair<int,int>> mp;
        get_height(0, root, mp);

        unordered_map<int,int> mpp;
        dfs(0, root, mpp, mp);

        vector<int> ans;
        for(auto q : queries) ans.push_back(mpp[q]);

        return ans;
    }
};

// 
class Solution {
public:
    int dfs(TreeNode* root, unordered_map<int,int>& height) {
        if(!root) return -1;
        int l = dfs(root->left, height);
        int r = dfs(root->right, height);
        int h = 1 + max(l, r);
        height[root->val] = h;
        return h;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int,int> height;
        dfs(root, height);

        queue<TreeNode*> q;
        q.push(root);

        unordered_map<int,int> mp;
        int lvl = 0;

        while(!q.empty()) {
            int sz = q.size();

            vector<int> v;
            multiset<int> st;

            while(sz--) {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                if(lvl > 0) {
                    v.push_back(curr->val);
                    st.insert(height[curr->val]);
                }
            }

            if(lvl > 0) {
                for(auto node : v) {
                    int node_height = height[node];
                    st.erase(st.find(node_height));
                    if(st.empty()) {
                        mp[node] = lvl - 1;
                    }
                    else {
                        int mx = *st.rbegin();
                        mp[node] = lvl + mx;
                    }
                    st.insert(node_height);
                }
            }
            lvl++;
        }

        vector<int> ans;
        for(auto q : queries) ans.push_back(mp[q]);

        return ans;
    }
};
