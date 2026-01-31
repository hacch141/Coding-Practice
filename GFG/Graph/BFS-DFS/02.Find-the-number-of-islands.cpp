// Find the number of islands

class Solution {
    private void dfs(int row, int col, char[][] grid, boolean[][] vis, int n, int m) {
        vis[row][col] = true;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nRow = row + i;
                int nCol = col + j;

                if (nRow >= 0 && nRow < n &&
                    nCol >= 0 && nCol < m &&
                    !vis[nRow][nCol] &&
                    grid[nRow][nCol] == '1') {

                    dfs(nRow, nCol, grid, vis, n, m);
                }
            }
        }
    }

    // Function to find the number of islands.
    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        boolean[][] vis = new boolean[n][m];
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid, vis, n, m);
                }
            }
        }

        return ans;
    }
}

// =========================================================

// BFS
class Solution {
    
    private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int& n, int& m) {
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    int nRow = r + i;
                    int nCol = c + j;
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]=='1') {
                        vis[nRow][nCol] = 1;
                        q.push({nRow,nCol});
                        
                    }
                    
                }
            }
        }
    }
        
    public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]=='1') {
                    ans++;
                    bfs(i,j,grid,vis,n,m);
                }
            }
        }
        
        return ans;
    }
};

// T : O(N*M)
// S : O(N*M)


// DFS
class Solution {
    
    private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int& n, int& m) {
        vis[row][col] = 1;
        
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                int nRow = row + i;
                int nCol = col + j;
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]=='1') {
                    dfs(nRow,nCol,grid,vis,n,m);
                }
            }
        }
    }
        
    public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]=='1') {
                    ans++;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }
        
        return ans;
    }
};

// T : O(N*M)
// S : O(N*M)
