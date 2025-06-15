// 64. Minimum Path Sum

// Rec
class Solution {
public:
    int dp[201][201];

    int solve(int i, int j, int& n, int& m, vector<vector<int>>& grid) {
        if(i == n - 1 && j == m - 1) return grid[i][j];
        if(i >= n || j >= m) return 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j + 1, n, m, grid);
        int down = solve(i + 1, j, n, m, grid);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, n, m, grid);
    }
};

// DP
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dp = grid;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i > 0 && j > 0) {
                    dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
                }
                else if(i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                else if(j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};
