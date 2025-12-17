// 3573. Best Time to Buy and Sell Stock V

class Solution {
    long[][][] dp;
    static final long NEG_INF = (long) -1e15;

    public long solve(int ind, int n, int[] prices, int k, int type) {
        if (ind >= n || k == 0) {
            return type == 0 ? 0 : NEG_INF;
        }

        if (dp[ind][k][type] != NEG_INF) return dp[ind][k][type];

        long ans = solve(ind + 1, n, prices, k, type);
        if (type == 0) {
            long normalTransaction = -prices[ind] + solve(ind + 1, n, prices, k, 1); // buy
            long shortSelling =       prices[ind] + solve(ind + 1, n, prices, k, 2); // sell
            ans = Math.max(ans, Math.max(normalTransaction, shortSelling));
        }
        else if (type == 1) {
            ans = Math.max(ans, prices[ind] + solve(ind + 1, n, prices, k - 1, 0));  // sell
        }
        else {
            ans = Math.max(ans, -prices[ind] + solve(ind + 1, n, prices, k - 1, 0));  // buy
        }

        return dp[ind][k][type] = ans;
    }

    public long maximumProfit(int[] prices, int k) {
        int n = prices.length;
        dp = new long[n][k + 1][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                Arrays.fill(dp[i][j], NEG_INF);
            }
        }
        return solve(0, n, prices, k, 0);
    }
}

