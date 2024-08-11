// 1568. Minimum Number of Days to Disconnect Island
class Solution {
public:

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        if(r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0 || vis[r][c] || grid[r][c] == 0) return;
        vis[r][c] = true;
        dfs(r + 1, c, grid, vis);
        dfs(r, c + 1, grid, vis);
        dfs(r - 1, c, grid, vis);
        dfs(r, c - 1, grid, vis);
    }

    int cntIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }

    int minDays(vector<vector<int>>& grid) {
        int cnt = cntIsland(grid);
        if(cnt != 1) return 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    cnt = cntIsland(grid);
                    if(cnt != 1) return 1;
                    grid[i][j] = 1;   
                }
            }
        }
        return 2;
    }
};
