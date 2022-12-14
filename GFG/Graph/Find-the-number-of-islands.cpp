// Find the number of islands

class Solution {
    
  private:
  void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid, int delRow[], int delCol[]) {
      vis[row][col] = 1;
      int n = grid.size();
      int m = grid[0].size();
      for(int i=0; i<8; i++) {
          int nRow = row+delRow[i];
          int nCol = col+delCol[i];
          if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]=='1' && !vis[nRow][nCol]) {
              dfs(nRow, nCol, vis, grid, delRow, delCol);
          }
      }
  }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int cnt = 0;
        int delRow[] = {-1, 0, +1, 0, -1, -1, +1, +1};
        int delCol[] = {0, +1, 0, -1, -1, +1, -1, +1};
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]=='1') {
                    cnt++;
                    dfs(i, j, vis, grid, delRow, delCol);
                }
            }
        }
        return cnt;
    }
};
