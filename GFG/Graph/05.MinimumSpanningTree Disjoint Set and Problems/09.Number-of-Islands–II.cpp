// Number of Islands – II

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};
        
        int cnt = 0;
        vector<int> ans;
        for(auto&it : operators) {
            int r = it[0];
            int c = it[1];
            if(vis[r][c]) {
                ans.push_back(cnt);
                continue;
            }
            vis[r][c] = 1;
            cnt++;
            
            for(int del=0; del<4; del++) {
                int newr = r + delRow[del];
                int newc = c + delCol[del];
                if(newr>=0 && newr<n && newc>=0 && newc<m) { 
                    if(vis[newr][newc]) {
                        int v = (m*newr) + newc;
                        int u = (m*r) + c;
                        if(ds.findPar(u) != ds.findPar(v)) {
                            cnt--;
                            ds.unionBySize(u,v);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

// T : O(m*n*4α)
// S : O(n*m)
