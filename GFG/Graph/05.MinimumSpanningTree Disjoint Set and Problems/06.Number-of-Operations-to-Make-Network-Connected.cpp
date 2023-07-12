// Minimize connections

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }
    
    int findPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u == ulp_v) {
            return;
        }
        if(size[ulp_v] > size[ulp_u]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution{
    public:
        int minimumConnections(vector<vector<int>> &c,int n)
        {
            // code here
            DisjointSet ds(n);
            int extra = 0;
            for(auto it : c) {
                int u = it[0];
                int v = it[1];
                if(ds.findPar(u) != ds.findPar(v)) {
                    ds.unionBySize(u,v);
                }
                else {
                    extra++;
                }
            }
            
            int cnt_comp = 0;
            for(int i=0; i<n; i++) {
                if(ds.findPar(i) == i) {
                    cnt_comp++;
                }
            }
            
            if(extra < cnt_comp - 1) return -1;
            return cnt_comp - 1;
        }
};

// T : O(E*4α) + O(V*4α)
// S : O(V)
