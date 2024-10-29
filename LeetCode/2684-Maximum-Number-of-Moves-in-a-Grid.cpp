// 2684. Maximum Number of Moves in a Grid

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int j = m - 1; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                int x = i - 1, y = j + 1;
                if(x >= 0 && y < m && grid[i][j] < grid[x][y]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[x][y]);
                }
                x = i, y = j + 1;
                if(x < n && y < m && grid[i][j] < grid[x][y]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[x][y]);
                }
                x = i + 1, y = j + 1;
                if(x < n && y < m && grid[i][j] < grid[x][y]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[x][y]);
                }
                if(j == 0) ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
