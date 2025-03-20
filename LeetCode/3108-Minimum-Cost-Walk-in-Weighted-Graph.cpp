// 3108. Minimum Cost Walk in Weighted Graph

class DisjointSet {
private:
    vector<int> sz, parent;
public:
    DisjointSet(int n) {
        sz.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find_par(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find_par(parent[u]);
    }

    void uinion_by_size(int u, int v) {
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
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet ds(n);
        for(auto &it : edges) {
            ds.uinion_by_size(it[0], it[1]);
        }

        vector<int> get_and(n, -1);
        for(auto &it : edges) {
            int par = ds.find_par(it[0]);
            if(get_and[par] == -1) get_and[par] = it[2];
            else get_and[par] &= it[2];
        }

        vector<int> ans;
        for(auto &it : query) {
            int par_u = ds.find_par(it[0]);
            int par_v = ds.find_par(it[1]);
            if(par_u == par_v) {
                ans.push_back(get_and[par_u]);
            }
            else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
