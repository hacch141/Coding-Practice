// Minimum number of deletions and insertions

class Solution {
    public int minDistance(String text1, String text2) {
        int n = text1.length(), m = text2.length();

        int[][] dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (text1.charAt(i) == text2.charAt(j)) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    if (i > 0) dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                    if (j > 0) dp[i][j] = Math.max(dp[i][j], dp[i][j - 1]);
                }
            }
        }

        return n + m - 2 * dp[n - 1][m - 1];
    }
}
