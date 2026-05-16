// Maximum Profit (K transaction)

class Solution {
    int[][][] dp;

    public int solve(int ind, int n, int canBuy, int transactions, int[] prices) {
        if (transactions < 0) return 0;
        if (ind == n) return 0;

        if (dp[ind][transactions][canBuy] != -1) return dp[ind][transactions][canBuy];

        int profit = solve(ind + 1, n, canBuy, transactions, prices);
        if (canBuy == 1) {
            profit = Math.max(profit, -prices[ind] + solve(ind + 1, n, 0, transactions - 1, prices));
        }
        else {
            profit = Math.max(profit, +prices[ind] + solve(ind + 1, n, 1, transactions, prices));
        }

        return dp[ind][transactions][canBuy] = profit;
    }

    public int maxProfit(int k, int[] prices) {
        int n = prices.length;

        dp = new int[n][k + 1][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        return solve(0, n, 1, k, prices);
    }
}
