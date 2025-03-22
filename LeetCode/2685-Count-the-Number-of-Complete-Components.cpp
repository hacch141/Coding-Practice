// 2685. Count the Number of Complete Components

class DisjointSet {
private:
    vector<int> parent, sz;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find_par(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find_par(parent[u]);
    }

    void union_by_size(int u, int v) {
        int par_u = find_par(u);
        int par_v = find_par(v);
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

    int get_cmp_size(int u) {
        return sz[u];
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto &it : edges) {
            ds.union_by_size(it[0], it[1]);
        }

        vector<int> cnt_edges(n, 0);
        for(auto &it : edges) {
            cnt_edges[ds.find_par(it[0])]++;
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(ds.find_par(i) != i) continue;
            int cmp_size = ds.get_cmp_size(i);
            ans += cnt_edges[i] == ((cmp_size * (cmp_size - 1)) / 2);
        }

        return ans;
    }
};
