// 3418. Maximum Amount of Money Robot Can Earn

class Solution {
    public int[][][] dp;

    public int solve(int i, int j, int n, int m, int[][] coins, int neuteralize) {
        if (i == n - 1 && j == m - 1) {
            return (neuteralize > 0) ? Math.max(coins[i][j], 0) : coins[i][j];
        }
        if (i == n || j == m) {
            return Integer.MIN_VALUE;
        }

        if (dp[i][j][neuteralize] != Integer.MIN_VALUE) return dp[i][j][neuteralize];

        int take = coins[i][j] + Math.max(solve(i + 1, j, n, m, coins, neuteralize), solve(i, j + 1, n, m, coins, neuteralize));
        int nottake = Integer.MIN_VALUE;
        if (coins[i][j] < 0 && neuteralize > 0) {
            nottake = Math.max(solve(i + 1, j, n, m, coins, neuteralize - 1), solve(i, j + 1, n, m, coins, neuteralize - 1));
        }

        return dp[i][j][neuteralize] = Math.max(take, nottake);
    }

    public int maximumAmount(int[][] coins) {
        int n = coins.length;
        int m = coins[0].length;
        dp = new int[n][m][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Arrays.fill(dp[i][j], Integer.MIN_VALUE);
            }
        }
        return solve(0, 0, n, m, coins, 2);
    }
}
