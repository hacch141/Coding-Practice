// 834. Sum of Distances in Tree

class Solution {
public:
    void dfs(int u, int par, vector<vector<int>>& adj, vector<int>& cnt, vector<int>& ans) {
        for(auto &v : adj[u]) {
            if(v == par) continue;
            dfs(v, u, adj, cnt, ans);
            cnt[u] += cnt[v];
            ans[u] += cnt[v] + ans[v];
        }
    }

    void dfs2(int u, int par, vector<vector<int>>& adj, vector<int>& cnt, vector<int>& ans, int& n) {
        for(auto &v : adj[u]) {
            if(v == par) continue;
            ans[v] = ans[u] - cnt[v] + (n - cnt[v]);
            dfs2(v, u, adj, cnt, ans, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> cnt(n, 1), ans(n, 0);
        dfs(0, -1, adj, cnt, ans);
        dfs2(0, 0, adj, cnt, ans, n);

        return ans;
    }
};
