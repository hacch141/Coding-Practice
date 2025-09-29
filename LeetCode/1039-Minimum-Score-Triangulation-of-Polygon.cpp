// 1039. Minimum Score Triangulation of Polygon

class Solution {
    public int solve(int l, int r, int[] values, int[][] dp) {
        if(r - l + 1 < 3) return 0;
        int mx = Integer.MAX_VALUE;
        if (dp[l][r] != -1) return dp[l][r];
        for(int m = l + 1; m < r; m++) {
            int curr = (values[l] * values[m] * values[r]) + solve(l, m, values, dp) + solve(m, r, values, dp);
            mx = Math.min(mx, curr);
        }
        return dp[l][r] = mx;
    }

    public int minScoreTriangulation(int[] values) {
        int n = values.length, ans = 0;
        int[][] dp = new int[n][n];
        for(int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(0, n - 1, values, dp);
    }
}
