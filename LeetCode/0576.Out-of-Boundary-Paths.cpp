// 576. Out of Boundary Paths


class Solution {
public:

    int mod = 1e9 + 7;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int dp[51][51][51];

    int solve(int r, int c, int& m, int& n, int maxMove) {
        if(r < 0 || c < 0 || r >= m || c >= n) return 1;

        if(dp[r][c][maxMove] != -1) return dp[r][c][maxMove];

        int ans = 0;
        if(maxMove > 0) {
            for(int i = 0; i < 4; i++) {
                ans += solve(r + dx[i], c + dy[i], m, n, maxMove - 1);
                ans %= mod;
            }
        }

        return dp[r][c][maxMove] = ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        for(int i = 0; i < 51; i++) {
            for(int j = 0; j < 51; j++) {
                for(int k = 0; k < 51; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(startRow, startColumn, m, n, maxMove);
    }
};
