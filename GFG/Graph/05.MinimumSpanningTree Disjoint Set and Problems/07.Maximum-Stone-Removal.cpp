// Maximum Stone Removal

class DisjointSet {
    vector<int> parent,size;
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
        if(size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones) {
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int,int> nodeStones;
        for(auto it : stones) {
            int u = it[0];
            int v = it[1] + maxRow + 1;
            ds.unionBySize(u,v);
            nodeStones[u] = 1;
            nodeStones[v] = 1;
        }
        
        int comp = 0;
        for(auto it : nodeStones) {
            int node = it.first;
            if(node == ds.findPar(node)) {
                comp++;
            }
        }
        
        return n - comp;
    }
};

// T : O(N * 4α)
// S : O(2* (max row index + max column index))
