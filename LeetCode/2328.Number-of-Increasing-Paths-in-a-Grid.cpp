// 2328. Number of Increasing Paths in a Grid

class Solution {
public:
    int MOD = 1e9 + 7;

    vector<int> dx = {-1, 0, +1, 0};
    vector<int> dy = {0, +1, 0, -1};

    int solve(int x1, int y1, int& n, int& m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if(dp[x1][y1] != -1) return dp[x1][y1];
        int cnt = 1;
        for(int i = 0; i < 4; i++) {
            int x2 = x1 + dx[i];
            int y2 = y1 + dy[i];
            if(x2 >= 0 && y2 >= 0 && x2 < n && y2 < m && grid[x2][y2] < grid[x1][y1]) {
                cnt = (cnt + solve(x2, y2, n, m, grid, dp)) % MOD;
            }
        }
        return dp[x1][y1] = cnt;
    }

    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = (ans + solve(i, j, n, m, grid, dp)) % MOD;
            }
        }
        return ans;
    }
};
