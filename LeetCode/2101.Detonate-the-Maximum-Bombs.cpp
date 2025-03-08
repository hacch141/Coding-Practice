// 2101. Detonate the Maximum Bombs

class Solution {
public:
    int dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;
        int cnt = 1;
        for(auto &v : adj[u]) {
            if(!vis[v]) cnt += dfs(v, adj, vis); 
        }
        return cnt;
    }

    bool is_detonatable(vector<int>& v1, vector<int>& v2) {
        long long x2 = 1LL * abs(v1[0] - v2[0]) * abs(v1[0] - v2[0]);
        long long y2 = 1LL * abs(v1[1] - v2[1]) * abs(v1[1] - v2[1]);
        return 1LL * v1[2] * v1[2] >= x2 + y2;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int u = 0; u < n; u++) {
            for(int v = 0; v < n; v++) {
                if(u == v) continue;
                if(is_detonatable(bombs[u], bombs[v])) adj[u].push_back(v);
            }
        }

        int mx = 0;
        for(int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            int cmp_cnt = dfs(i, adj, vis);
            mx = max(mx, cmp_cnt);
        }

        return mx;
    }
};
