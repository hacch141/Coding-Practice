// Longest Palindromic Subsequence

class Solution {
    public int longestPalindromeSubseq(String A) {
        int n = A.length();

        String B = new StringBuilder(A).reverse().toString();
        int[][] dp = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (A.charAt(i) == B.charAt(j)) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    if (i > 0) dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                    if (j > 0) dp[i][j] = Math.max(dp[i][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n - 1][n - 1];
    }
}
