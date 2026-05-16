// Buy Stock with Transaction Fee

class Solution {
    int[][] dp;

    public int solve(int ind, int n, int canBuy, int[] prices, int fee) {
        if (ind >= n) return 0;

        if (dp[ind][canBuy] != -1) return dp[ind][canBuy];

        int profit = solve(ind + 1, n, canBuy, prices, fee);
        if (canBuy == 1) {
            profit = Math.max(profit, -prices[ind] -fee + solve(ind + 1, n, 0, prices, fee));
        } else {
            profit = Math.max(profit, +prices[ind] + solve(ind + 1, n, 1, prices, fee));
        }

        return dp[ind][canBuy] = profit;
    }
    
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;

        dp = new int[n][2];
        for (int i = 0; i < n; i++) Arrays.fill(dp[i], -1);

        return solve(0, n, 1, prices, fee);
    }
}
