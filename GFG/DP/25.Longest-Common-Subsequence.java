// Longest Common Subsequence

class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
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

        return dp[n - 1][m - 1];
    }
}

class Solution {
    int[][] dp;

    public int solve(int ind1, int n, int ind2, int m, String s1, String s2) {
        if (ind1 == n || ind2 == m) return 0;

        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int lcs = -1;
        if (s1.charAt(ind1) == s2.charAt(ind2)) {
            lcs = 1 + solve(ind1 + 1, n, ind2 + 1, m, s1, s2);
        }
        else {
            lcs = Math.max(solve(ind1 + 1, n, ind2, m, s1, s2), solve(ind1, n, ind2 + 1, m, s1, s2));
        }

        return dp[ind1][ind2] = lcs;
    }

    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length(), m = text2.length();

        dp = new int[n][m];
        for (int i = 0; i < n; i++) Arrays.fill(dp[i], -1);

        return solve(0, n, 0, m, text1, text2);
    }
}
