class Solution
{
    private:
    int dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        int cnt = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<8; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==1) {
                cnt += dfs(nRow, nCol, vis, grid, delRow, delCol);
            }
        }
        return cnt;
    }
    
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int delRow[] = {-1, 0, +1, 0, 1, 1, -1, -1};
        int delCol[] = {0, +1, 0, -1, 1, -1, 1, -1};
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    ans = max(ans,dfs(i, j, vis, grid, delRow, delCol));
                }
            }
        }
        return ans;
    }
};
