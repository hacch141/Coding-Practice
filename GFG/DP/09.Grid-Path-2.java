// Grid Path 2

// Memoization
class Solution {

    int mod = 1000000007;

    int solve(int n, int m, int[][] grid, int[][] dp) {

        if (n >= 0 && m >= 0 && grid[n][m] == 1) {
            return 0;
        }

        if (n == 0 && m == 0) {
            return 1;
        }

        if (n < 0 || m < 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        int up = solve(n - 1, m, grid, dp);

        int left = solve(n, m - 1, grid, dp);

        return dp[n][m] = (up + left) % mod;
    }

    public int totalWays(int n, int m, int[][] grid) {

        int[][] dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = -1;
            }
        }

        return solve(n - 1, m - 1, grid, dp);
    }
}
// T : O(M * N)
// S : O(M * N) + Stack Space


// =======================================================================


// Tabulation
class Solution {

    int mod = 1000000007;

    public int totalWays(int n, int m, int[][] grid) {

        int[][] dp = new int[n][m];

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0 && grid[0][0] != 1) {

                    dp[i][j] = 1;

                } else if (grid[i][j] == 1) {

                    dp[i][j] = 0;

                } else {

                    int left = 0;
                    int up = 0;

                    if (i > 0) up = dp[i - 1][j];

                    if (j > 0) left = dp[i][j - 1];

                    dp[i][j] = (up + left) % mod;
                }
            }
        }

        return dp[n - 1][m - 1];
    }
}
// T : O(M * N)
// S : O(M * N)


// =======================================================================


// Space Optimization
class Solution {

    int mod = 1000000007;

    public int totalWays(int n, int m, int[][] grid) {

        int[] prev = new int[m];

        for (int i = 0; i < n; i++) {

            int[] curr = new int[m];

            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0 && grid[0][0] != 1) {

                    curr[j] = 1;

                } else if (grid[i][j] == 1) {

                    curr[j] = 0;

                } else {

                    int left = 0;
                    int up = 0;

                    if (i > 0) up = prev[j];

                    if (j > 0) left = curr[j - 1];

                    curr[j] = (up + left) % mod;
                }
            }

            prev = curr;
        }

        return prev[m - 1];
    }
}
// T : O(M * N)
// S : O(2 * M)
