// 1254. Number of Closed Islands

class Solution {

private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==0) {
                dfs(nRow, nCol, vis, grid, delRow, delCol);
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        // for(int i=0; i<n; i++) {
        //     if(!vis[i][0] && grid[i][0]==0) {
        //         dfs(i, 0, vis, grid, delRow, delCol);
        //     }
        //     if(!vis[i][m-1] && grid[i][m-1]==0) {
        //         dfs(i, m-1, vis, grid, delRow, delCol);
        //     }
        // }
        // for(int j=0; j<m; j++) {
        //     if(!vis[0][j] && grid[0][j]==0) {
        //         dfs(0, j, vis, grid, delRow, delCol);
        //     }
        //     if(!vis[n-1][j] && grid[n-1][j]==0) {
        //         dfs(n-1, j, vis, grid, delRow, delCol);
        //     }
        // }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((i==0 || j==0 || i==n-1 || j==m-1) && !vis[i][j] && grid[i][j]==0) {
                    dfs(i, j, vis, grid, delRow, delCol);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]==0) {
                    dfs(i, j, vis, grid, delRow, delCol);
                    ans++;
                }
            }
        }
        return ans;
    }
};
