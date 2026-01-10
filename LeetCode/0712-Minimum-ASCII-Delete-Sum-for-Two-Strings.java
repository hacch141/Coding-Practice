// 712. Minimum ASCII Delete Sum for Two Strings

class Solution {
    public int[][] dp;

    public int solve(int ind1, int n1, int ind2, int n2, String s1, String s2) {
        if (ind1 >= n1 && ind2 >= n2) return 0;

        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

        // if one string is completed
        if (ind1 >= n1) return (int)(s2.charAt(ind2)) + solve(ind1, n1, ind2 + 1, n2, s1, s2);
        if (ind2 >= n2) return (int)(s1.charAt(ind1)) + solve(ind1 + 1, n1, ind2, n2, s1, s2);

        // if both have some remaining chars in it
        if (s1.charAt(ind1) == s2.charAt(ind2)) return solve(ind1 + 1, n1, ind2 + 1, n2, s1, s2);
        int delete1 = (int)(s1.charAt(ind1)) + solve(ind1 + 1, n1, ind2, n2, s1, s2);
        int delete2 = (int)(s2.charAt(ind2)) + solve(ind1, n1, ind2 + 1, n2, s1, s2);

        return dp[ind1][ind2] = Math.min(delete1, delete2);
    }

    public int minimumDeleteSum(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();
        dp = new int[n1 + 1][n2 + 1];
        for (int i = 0; i <= n1; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(0, n1, 0, n2, s1, s2);
    }
}
