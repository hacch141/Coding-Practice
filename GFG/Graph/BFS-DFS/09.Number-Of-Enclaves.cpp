// Number Of Enclaves

class Solution {

    private void dfs(int row, int col, int[][] grid, boolean[][] vis, int n, int m) {
        vis[row][col] = true;
        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, -1, 0, 1};

        for (int d = 0; d < 4; d++) {
            int nRow = row + delRow[d];
            int nCol = col + delCol[d];

            if (nRow >= 0 && nRow < n &&
                nCol >= 0 && nCol < m &&
                !vis[nRow][nCol] &&
                grid[nRow][nCol] == 1) {

                dfs(nRow, nCol, grid, vis, n, m);
            }
        }
    }

    public int numEnclaves(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        boolean[][] vis = new boolean[n][m];

        // Left & Right boundaries
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, grid, vis, n, m);
            }
            if (!vis[i][m - 1] && grid[i][m - 1] == 1) {
                dfs(i, m - 1, grid, vis, n, m);
            }
        }

        // Top & Bottom boundaries
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, grid, vis, n, m);
            }
            if (!vis[n - 1][j] && grid[n - 1][j] == 1) {
                dfs(n - 1, j, grid, vis, n, m);
            }
        }

        // Count enclave land cells
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
}

// =============================================================

// BFS
class Solution {
    
  private:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m) {
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, -1, 0, 1};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int del = 0; del < 4; del++) {
                int nRow = r + delRow[del];
                int nCol = c + delCol[del];
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
    
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && grid[i][0] == 1) {
                bfs(i, 0, grid, vis, n, m);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1) {
                bfs(i, m-1, grid, vis, n, m);
            }
        }

        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && grid[0][j] == 1) {
                bfs(0, j, grid, vis, n, m);
            }
            if(!vis[n-1][j] && grid[n-1][j] == 1) {
                bfs(n-1, j, grid, vis, n, m);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// T : O(M*N)
// S:  O(M*N)

// DFS
class Solution {
    
  private:
  
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m) {
        vis[row][col] = 1;
        
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, -1, 0, 1};

        for(int del=0; del<4; del++) {
            int nRow = row + delRow[del];
            int nCol = col + delCol[del];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==1) {
                dfs(nRow,nCol,grid,vis,n,m);
            }
        }
    }
    
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            if(!vis[i][0] && grid[i][0] == 1) {
                dfs(i, 0, grid, vis, n, m);
            }
            if(!vis[i][m - 1] && grid[i][m - 1] == 1) {
                dfs(i, m - 1, grid, vis, n, m);
            }
        }

        for(int j = 0; j < m; j++) {
            if(!vis[0][j] && grid[0][j] == 1) {
                dfs(0, j, grid, vis, n, m);
            }
            if(!vis[n - 1][j] && grid[n - 1][j] == 1) {
                dfs(n - 1, j, grid, vis, n, m);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// T : O(N*M)
// S : O(N*M)
