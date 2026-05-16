// Buy Stock 2

class Solution {
    private long solve(int idx, int n, int buy, int[] prices, long[][] dp) {
        if (idx == n) return 0;

        if (dp[idx][buy] != -1) return dp[idx][buy];

        long profit;
        if (buy == 1) {
            long buyStock = -prices[idx] + solve(idx + 1, n, 0, prices, dp);
            long skip = solve(idx + 1, n, 1, prices, dp);
            profit = Math.max(buyStock, skip);
        } else {
            long sellStock = prices[idx] + solve(idx + 1, n, 1, prices, dp);
            long skip = solve(idx + 1, n, 0, prices, dp);
            profit = Math.max(sellStock, skip);
        }

        return dp[idx][buy] = profit;
    }

    public int maxProfit(int[] prices) {
        int n = prices.length;

        long[][] dp = new long[n][2];
        for (int i = 0; i < n; i++) Arrays.fill(dp[i], -1);

        return (int) solve(0, n, 1, prices, dp);
    }
}
