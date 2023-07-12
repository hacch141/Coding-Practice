// Making a Large Island

class DisjointSet {
public:
    vector<int> parent, size;
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
            parent[ulp_v] = parent[ulp_u];
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = parent[ulp_v];
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        DisjointSet ds(n*m);
        
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};
        
        for(int r=0; r<n; r++) {
            for(int c=0; c<m; c++) {
                if(grid[r][c] == 0) {
                    continue;
                }
                for(int del=0; del<4; del++) {
                    int newr = r + delRow[del];
                    int newc = c + delCol[del];
                    if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1) {
                        int u = (m*r) + c;
                        int v = (m*newr) + newc;
                        ds.unionBySize(u,v);
                    }
                }
            }
        }
        
        int ans = 0;
        for(int r=0; r<n; r++) {
            for(int c=0; c<m; c++) {
                if(grid[r][c] == 1) {
                    continue;
                }
                set<int> comp;
                for(int del=0; del<4; del++) {
                    int newr = r + delRow[del];
                    int newc = c + delCol[del];
                    if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1) {
                        int u = (m*r) + c;
                        int v = (m*newr) + newc;
                        comp.insert(ds.findPar(v));
                    }
                }
                int newsize = 0;
                for(auto i : comp) {
                    newsize += ds.size[i];
                }
                ans = max(ans,newsize+1);
            }
        }
        
        for(int cell=0; cell<m*n; cell++) {
            ans = max(ans,ds.size[cell]);
        }
        
        return ans;
    }
};

// T : O(N*M*4α)
// S : O(2*N*M)
