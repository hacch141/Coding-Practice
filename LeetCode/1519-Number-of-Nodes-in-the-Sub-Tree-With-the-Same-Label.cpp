// 1519. Number of Nodes in the Sub-Tree With the Same Label

class Solution {
public:
    vector<int> dfs(int u, int par, vector<vector<int>>& adj, string& labels, vector<int>& ans) {
        vector<int> f(26, 0);
        for(auto &v : adj[u]) {
            if(v == par) continue;
            auto child = dfs(v, u, adj, labels, ans);
            for(int i = 0; i < 26; i++) {
                f[i] += child[i];
            }
        }
        f[labels[u] - 'a']++;
        ans[u] = f[labels[u] - 'a'];
        return f;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> ans(n);
        dfs(0, -1, adj, labels, ans);

        return ans;
    }
};
