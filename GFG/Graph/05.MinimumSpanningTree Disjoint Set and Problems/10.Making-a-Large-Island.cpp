// Making a Large Island

class DisjointSet {
    int[] parent, size;
    public DisjointSet(int n) {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int findParent(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }

    public void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_v] > size[ulp_u]) {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
        else {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }

    public int getComponentSize(int u) {
        int ulp_u = findParent(u);
        return size[ulp_u];
    }
}

class Solution {
    int[] delRow = {-1, 0, +1, 0};
    int[] delCol = {0, +1, 0, -1};

    public int largestIsland(int[][] grid) {
        int n = grid.length, m = grid[0].length;

        DisjointSet ds = new DisjointSet(n * m);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) continue;
                int u = (i * m) + j;
                for (int d = 0; d < 4; d++) {
                    int nRow = i + delRow[d];
                    int nCol = j + delCol[d];
                    int v = (nRow * m) + nCol;
                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1) {
                        if (ds.findParent(u) != ds.findParent(v)) {
                            ds.unionBySize(u, v);
                            ans = Math.max(ans, ds.getComponentSize(u));
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) continue;
                int u = (i * m) + j;

                Set<Integer> st = new HashSet<>();
                for (int d = 0; d < 4; d++) {
                    int nRow = i + delRow[d];
                    int nCol = j + delCol[d];
                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1) {
                        int v = (nRow * m) + nCol;
                        st.add(ds.findParent(v));
                    }
                }

                int curr = 1;
                for (int p : st) {
                    curr += ds.getComponentSize(p);
                }

                ans = Math.max(ans, curr);
            }
        }

        return ans;
    }
}

// =================================================================================

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
