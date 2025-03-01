// 947. Most Stones Removed with Same Row or Column

class DisjointSet {
private:
    vector<int> size, par;
public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        par.resize(n + 1);
        for(int i = 0; i <= n; i++) par[i] = i;
    }

    int find_par(int u) {
        if(par[u] == u) return u;
        return par[u] = find_par(par[u]);
    }

    void union_by_size(int u, int v) {
        int par_u = find_par(u);
        int par_v = find_par(v);
        if(par_u == par_v) {
            return;
        }
        else if(size[par_u] > size[par_v]) {
            size[par_u] += size[par_v];
            par[par_v] = par_u;
        }
        else {
            size[par_v] += size[par_u];
            par[par_u] = par_v;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);

        DisjointSet ds(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                else if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    ds.union_by_size(i, j);
                }
            }
        }

        set<int> st;
        for(int i = 0; i < n; i++) {
            st.insert(ds.find_par(i));
        }

        return n - st.size();
    }
};

// ===============================================================================

class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;
        for(auto &v : adj[u]) {
            if(!vis[v]) dfs(v, adj, vis);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                else if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                cnt++;
            }
        }

        return n - cnt;
    }
};

// ===============================================================================

class Solution {
public:
    void dfs(int row, int col, map<int,vector<int>>& adj_row, map<int,vector<int>>& adj_col, set<int>& vis_row, set<int>& vis_col) {
        vis_row.insert(row);
        vis_col.insert(col);

        for(auto &r : adj_row[col]) {
            if(vis_row.count(r)) continue;
            dfs(r, col, adj_row, adj_col, vis_row, vis_col);
        }
        
        for(auto &c : adj_col[row]) {
            if(vis_col.count(c)) continue;
            dfs(row, c, adj_row, adj_col, vis_row, vis_col);
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        map<int,vector<int>> adj_row, adj_col;
        for(auto &cod : stones) {
            adj_row[cod[1]].push_back(cod[0]);
            adj_col[cod[0]].push_back(cod[1]);
        }

        int cnt = 0;
        set<int> vis_row, vis_col;
        for(auto &cod : stones) {
            if(vis_row.count(cod[0]) && vis_col.count(cod[1])) continue;
            dfs(cod[0], cod[1], adj_row, adj_col, vis_row, vis_col);
            cnt++;
        }

        return stones.size() - cnt;
    }
};
