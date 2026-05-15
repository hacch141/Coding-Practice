// Shortest Common Supersequence

class Solution {
    public String shortestCommonSupersequence(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();

        int[][] dp = new int[n1][n2];
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    if (i > 0) dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                    if (j > 0) dp[i][j] = Math.max(dp[i][j], dp[i][j - 1]);
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        int p1 = n1 - 1, p2 = n2 - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (s1.charAt(p1) == s2.charAt(p2)) {
                sb.append(s1.charAt(p1));
                p1--;
                p2--;
            }
            else if (p1 > 0 && dp[p1][p2] == dp[p1 - 1][p2]) {
                sb.append(s1.charAt(p1));
                p1--;
            }
            else if (p2 > 0 && dp[p1][p2] == dp[p1][p2 - 1]) {
                sb.append(s2.charAt(p2));
                p2--;
            }
            else {
                break;
            }
        }
        while (p1 >= 0) {
            sb.append(s1.charAt(p1));
            p1--;
        }
        while (p2 >= 0) {
            sb.append(s2.charAt(p2));
            p2--;
        }

        return sb.reverse().toString();
    }
}
