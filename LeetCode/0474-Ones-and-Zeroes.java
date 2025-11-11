// 474. Ones and Zeroes

class Solution {
    public int solve(int ind, int len, int[] zeros, int[] ones, int m, int n, int[][][] dp) {
        if (m < 0 || n < 0) return Integer.MIN_VALUE;
        if (ind == len) return 0;
        if (dp[ind][m][n] != -1) return dp[ind][m][n];
        int take = 1 + solve(ind + 1, len, zeros, ones, m - zeros[ind], n - ones[ind], dp);
        int nottake = solve(ind + 1, len, zeros, ones, m, n, dp);
        return dp[ind][m][n] = Math.max(take, nottake);
    }

    public int findMaxForm(String[] strs, int m, int n) {
        int len = strs.length;
        int[] zeros = new int[len];
        int[] ones = new int[len];
        for (int i = 0; i < len; i++) {
            int zero = 0, one = 0;
            for (char ch : strs[i].toCharArray()) {
                if (ch == '0') zero++;
                else one++;
            }
            zeros[i] = zero;
            ones[i] = one;
        }

        int[][][] dp = new int[len][m + 1][n + 1];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j <= m; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        return solve(0, len, zeros, ones, m, n, dp);
    }
}
