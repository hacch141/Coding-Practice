// 980. Unique Paths III

class Solution {

private:

    bool visCheck(vector<vector<int>>& grid, vector<vector<int>> &vis, int n, int m) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0 && vis[i][j] == 0) return false;
            }
        }
        return true;
    }

    void solve(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid, int delRow[], int delCol[], int &ans) {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        if(grid[row][col]==2) {
            if(visCheck(grid,vis,n,m)) {
                ans++;
            }
            vis[row][col] = 0;
            return;
        }
        for(int i=0; i<4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]!=-1 && grid[nRow][nCol]!=1) {
                solve(nRow, nCol, vis, grid, delRow, delCol, ans);
            }
        }
        vis[row][col] = 0;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int delRow[] = {0,-1,0,1};
        int delCol[] = {-1,0,+1,0};
        vector<vector<int>> vis(n, vector<int> (m,0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==1) {
                    solve(i,j,vis,grid,delRow,delCol,ans);
                    break;
                }
            }
        }
        return ans;
    }
};
