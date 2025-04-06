// 2658. Maximum Number of Fish in a Grid

class Solution {
public:

    vector<int> dx = {-1, 0, +1, 0};
    vector<int> dy = {0, +1, 0, -1};

    int dfs(int i, int j, int& n, int& m, vector<vector<int>>& grid) {
        int fish = grid[i][j];
        grid[i][j] = 0;
        for(int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != 0) {
                fish += dfs(nx, ny, n, m, grid);
            }
        }
        return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != 0) {
                    ans = max(ans, dfs(i, j, n, m, grid));
                }
            }
        }

        return ans;
    }
};
