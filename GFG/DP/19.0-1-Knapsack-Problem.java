// 0 - 1 Knapsack Problem

class Solution {
    int[][] dp;
    
    public int solve(int ind, int n, int[] val, int[] wt, int capacity) {
        if (ind == n) return 0;
        
        if (dp[ind][capacity] != -1) return dp[ind][capacity];
        
        int nottake = solve(ind + 1, n, val, wt, capacity);
        int take = Integer.MIN_VALUE;
        if (wt[ind] <= capacity) {
            take = val[ind] + solve(ind, n, val, wt, capacity - wt[ind]);
        }
        return dp[ind][capacity] = Math.max(take, nottake);
    }
    
    public int knapSack(int val[], int wt[], int capacity) {
        // code here
        int n = val.length;

        dp = new int[n][capacity + 1];
        for (int i = 0; i < n; i++) Arrays.fill(dp[i], -1);

        return solve(0, n, val, wt, capacity);
    }
}
