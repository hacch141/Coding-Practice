// 684. Redundant Connection

class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis, int uu, int vv) {
        vis[u] = true;
        for(auto &v : adj[u]) {
            if((u == uu && v == vv) || (u == vv && v == uu)) continue;
            if(!vis[v]) {
                dfs(v, adj, vis, uu, vv);
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> ans;
        for(auto it : edges) {
            vector<bool> vis(n + 1, false);
            bool f = true;
            dfs(1, adj, vis, it[0], it[1]);
            for(int u = 1; u <= n; u++) if(!vis[u]) f = false;
            if(f) ans = it;
        }

        return ans;
    }
};
