// Number of Unique Paths

// Memoization
class Solution {

    int solve(int i, int j, int[][] dp) {

        if (i == 0 && j == 0) return 1;

        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int left = solve(i, j - 1, dp);

        int up = solve(i - 1, j, dp);

        return dp[i][j] = left + up;
    }

    // Function to find total number of unique paths
    public int NumberOfPath(int a, int b) {

        int[][] dp = new int[a][b];

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                dp[i][j] = -1;
            }
        }

        return solve(a - 1, b - 1, dp);
    }
}
// T : O(M * N)
// S : O(M * N) + Stack Space


// =======================================================================


// Tabulation
class Solution {

    // Function to find total number of unique paths
    public int NumberOfPath(int a, int b) {

        int[][] dp = new int[a][b];

        for (int i = 0; i < a; i++) {

            for (int j = 0; j < b; j++) {

                if (i == 0 && j == 0) {

                    dp[i][j] = 1;

                } else {

                    int left = 0;
                    int up = 0;

                    if (j > 0) left = dp[i][j - 1];

                    if (i > 0) up = dp[i - 1][j];

                    dp[i][j] = left + up;
                }
            }
        }

        return dp[a - 1][b - 1];
    }
}
// T : O(M * N)
// S : O(M * N)


// =======================================================================


// Space Optimization
class Solution {

    // Function to find total number of unique paths
    public int NumberOfPath(int a, int b) {

        int[] prev = new int[b];

        for (int i = 0; i < a; i++) {

            int[] curr = new int[b];

            curr[0] = 1;

            for (int j = 1; j < b; j++) {

                int left = curr[j - 1];

                int up = 0;

                if (i > 0) {
                    up = prev[j];
                }

                curr[j] = left + up;
            }

            prev = curr;
        }

        return prev[b - 1];
    }
}
// T : O(M * N)
// S : O(2 * N)
