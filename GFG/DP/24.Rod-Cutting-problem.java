// Rod Cutting

class Solution {
    int INF = (int)1e9;
    int[][] dp;
    
    public int solve(int ind, int n, int[] price, int curr) {
        if (curr < 0) return -INF;
        if (ind == n) return curr == 0 ? 0 : -INF;
        
        if (dp[ind][curr] != -1) return dp[ind][curr];
        
        int take = price[ind] + solve(ind, n, price, curr - (ind + 1));
        int nottake = solve(ind + 1, n, price, curr);
        return dp[ind][curr] = Math.max(take, nottake);
    }
    
    public int cutRod(int[] price) {
        // code here
        int n = price.length;
        
        dp = new int[n][n + 1];
        for (int i = 0; i < n; i++) Arrays.fill(dp[i], -1);

        return solve(0, n, price, n);
    }
}
