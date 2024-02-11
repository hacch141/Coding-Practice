// 1463. Cherry Pickup II

class Solution {
public:

    int dp[70][70][70];

    int solve(int i, int j1, int j2, int& n, int& m, vector<vector<int>>& grid) {
        if(i == n) return 0;

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int res = grid[i][j1] + grid[i][j2], mx = 0;
        if(j1 == j2) res /= 2;

        for(int x = -1; x <= 1; x++) {
            for(int y = -1; y <= 1; y++) {
                int dj1 = j1 + x;
                int dj2 = j2 + y;
                if(dj1 >= 0 && dj2 >= 0 && dj1 < m && dj2 < m) {
                    mx = max(mx, solve(i + 1, dj1, dj2, n, m, grid));
                }
            }
        }

        return dp[i][j1][j2] = res + mx;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < 70; i++) {
            for(int j = 0; j < 70; j++) {
                for(int k = 0; k < 70; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(0, 0, m - 1, n, m, grid);
    }
};
