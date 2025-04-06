// 684. Redundant Connection

//bfs
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        vector<int> ans;

        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(auto &it : edges) {
            int uu = it[0], vv = it[1];

            queue<int> q;
            q.push(1);

            vector<bool> vis(n + 1, false);
            vis[1] = true;

            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(auto &v : adj[u]) {
                    if(vis[v]) continue;
                    if((u == uu && v == vv) || (u == vv && v == uu)) continue;
                    q.push(v);
                    vis[v] = true;
                }
            }

            bool f = true;
            for(int i = 1; i <= n; i++) {
                if(!vis[i]) {
                    f = false;
                    break;
                }
            }

            if(f) ans = it;
        }

        return ans;
    }
};

// ====================================================================================

// dfs
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

// ==========================================================================

// DSU
class DisjointSet {
private:
    vector<int> parent, sz;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int find_par(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find_par(parent[u]);
    }

    void union_by_size(int u, int v) {
        int par_u = find_par(u), par_v = find_par(v);
        if(par_u == par_v) {
            return;
        }
        else if(sz[par_u] > sz[par_v]) {
            sz[par_u] += sz[par_v];
            parent[par_v] = par_u;
        }
        else {
            sz[par_v] += sz[par_u];
            parent[par_u] = par_v;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for(auto &it : edges) {
            int u = it[0], v = it[1];
            if(ds.find_par(u) == ds.find_par(v)) {
                return it;
            }
            ds.union_by_size(u, v);
        }

        return {};
    }
};
