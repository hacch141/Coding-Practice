// 695. Max Area of Island

class Solution {

// 1st DFS
private:
    int dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid, int delRow[], int delCol[]) {
        vis[row][col] = 1;
        int area = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 &&nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==1) {
                area += dfs(nRow, nCol, vis, grid, delRow, delCol);
            }
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        int ans = 0;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
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

// 2nd DFS
class Solution {
public:
    
    int dfs(vector<vector<int>> &grid, int i, int j) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0) {
            return 0;
        }
        grid[i][j] = 0;
        int area = 1;
        area += dfs(grid, i+1, j);
        area += dfs(grid, i-1, j);
        area += dfs(grid, i, j+1);
        area += dfs(grid, i, j-1);
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]==1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};
