// Coin Change

class Solution {
    int[][] dp;

    public int solve(int ind, int n, int[] coins, int amount) {
        if (amount < 0) return 0;
        if (ind == n) return amount == 0 ? 1 : 0;

        if (dp[ind][amount] != -1) return dp[ind][amount];

        int take = solve(ind, n, coins, amount - coins[ind]);
        int nottake = solve(ind + 1, n, coins, amount);

        return dp[ind][amount] = take + nottake;
    }

    public int change(int amount, int[] coins) {
        int n = coins.length;

        dp = new int[n][amount + 1];
        for (int i = 0; i < n; i++) Arrays.fill(dp[i], -1);

        return solve(0, n, coins, amount);
    }
}
