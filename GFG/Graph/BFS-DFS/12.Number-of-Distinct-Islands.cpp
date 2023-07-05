// Number of Distinct Islands

// BFS
class Solution {
    
  private:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int& n, int& m, vector<pair<int,int>>& v) {
        vis[row][col] = 1;
        int baseR = row;
        int baseC = col;
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};
        
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            v.push_back({r-baseR,c-baseC});
            q.pop();
            for(int del=0; del<4; del++) {
                int nRow = r + delRow[del];
                int nCol = c + delCol[del];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==1) {
                    vis[nRow][nCol] = 1;
                    q.push({nRow,nCol});
                }
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int,int>> > s;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    vector<pair<int,int>> v;
                    bfs(i,j,grid,vis,n,m,v);
                    s.insert(v);
                }
            }
        }
        
        return s.size();
    }
};

// T : O(M*N)
// S : O(M*N)


// DFS
class Solution {
    
  private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int& n, int& m, vector<pair<int,int>>& v, int& baseR, int& baseC) {
        vis[row][col] = 1;
        v.push_back({row-baseR,col-baseC});
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};
        
        for(int del=0; del<4; del++) {
            int nRow = row + delRow[del];
            int nCol = col + delCol[del];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==1) {
                dfs(nRow,nCol,grid,vis,n,m,v,baseR,baseC);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<vector<pair<int,int>> > s;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    vector<pair<int,int>> v;
                    dfs(i,j,grid,vis,n,m,v,i,j);
                    s.insert(v);
                }
            }
        }
        
        return s.size();
    }
};

// T : O(M*N)
// S : O(M*N)
