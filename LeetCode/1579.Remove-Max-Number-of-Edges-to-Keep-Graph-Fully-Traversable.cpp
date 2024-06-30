// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable

// ======================================== DISJOINT SET ==============================================
class DisjointSet {
public:
    vector<int> parent,rank;
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++) parent[i] = i;
    }
    
    int par(int node) {
        return parent[node] = ((node == parent[node]) ? node : par(parent[node]));
    }
    
    void add(int u, int v) {
        int ulp_u = par(u), ulp_v = par(v);
        if(ulp_u != ulp_v) {
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    }

    void remove(int u) {
        parent[u] = u;
    }
};
// ====================================================================================================

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet ds1(n), ds2(n);
        sort(edges.rbegin(),edges.rend());
        int edgsUsed = 0;
        for(auto i : edges) {
            int type = i[0], u = i[1], v = i[2];
            if(type == 3) {
                if(ds1.par(u) != ds1.par(v)) {
                    ds1.add(u, v);
                    ds2.add(u, v);
                    edgsUsed++;
                }
            }
            else if(type == 1) {
                if(ds1.par(u) != ds1.par(v)) {
                    ds1.add(u, v);
                    edgsUsed++;
                }
            }
            else if(type == 2) {
                if(ds2.par(u) != ds2.par(v)) {
                    ds2.add(u, v);
                    edgsUsed++;
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if(ds1.par(1) != ds1.par(i) || ds2.par(1) != ds2.par(i)) return -1;
        }
        
        return edges.size() - edgsUsed;
    }
};
