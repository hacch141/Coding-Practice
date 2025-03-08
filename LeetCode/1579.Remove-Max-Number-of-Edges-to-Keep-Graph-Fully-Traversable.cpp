// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable

class DisjointSet {
private:
    vector<int> parent, sz;
public:
    DisjointSet(int n ) {
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.rbegin(), edges.rend());

        int cnt = 0;
        DisjointSet ds1(n), ds2(n);
        for(auto &it : edges) {
            int type = it[0], u = it[1], v = it[2];
            if(type == 3) {
                if(ds1.find_par(u) != ds1.find_par(v)) {
                    ds1.union_by_size(u, v);
                    ds2.union_by_size(u, v);
                }
                else {
                    cnt++;
                }
            }
            else if(type == 1) {
                if(ds1.find_par(u) != ds1.find_par(v)) {
                    ds1.union_by_size(u, v);
                }
                else {
                    cnt++;
                }
            }
            else if(type == 2) {
                if(ds2.find_par(u) != ds2.find_par(v)) {
                    ds2.union_by_size(u, v);
                }
                else {
                    cnt++;
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if(ds1.find_par(i) != ds1.find_par(1) || ds2.find_par(i) != ds2.find_par(1)) return -1;
        }

        return cnt;
    }
};
