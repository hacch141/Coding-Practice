// Longest Common Substring

class Solution {
    public int longCommSubstr(String s1, String s2) {
        // code here
        int n1 = s1.length(), n2 = s2.length();
        int[][] dp = new int[n1][n2];
        
        int ans = 0;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 0;
                }
                ans = Math.max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
}
