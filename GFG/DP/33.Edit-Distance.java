// Edit Distance


class Solution {
    int[][] dp;

    public int solve(int ind1, int ind2, int n1, int n2, String s1, String s2) {
        if (ind1 == n1) return n2 - ind2;
        if (ind2 == n2) return n1 - ind1;

        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int ans = Integer.MAX_VALUE;
        if (s1.charAt(ind1) == s2.charAt(ind2)) {
            ans = solve(ind1 + 1, ind2 + 1, n1, n2, s1, s2);
        }
        else {
            int delete = 1 + solve(ind1 + 1, ind2, n1, n2, s1, s2);
            int insert = 1 + solve(ind1, ind2 + 1, n1, n2, s1, s2);
            int replace = 1 + solve(ind1 + 1, ind2 + 1, n1, n2, s1, s2);
            ans = Math.min(delete, Math.min(insert, replace));
        }

        return dp[ind1][ind2] = ans;
    }

    public int minDistance(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();

        dp = new int[n1][n2];
        for (int i = 0; i < n1; i++) Arrays.fill(dp[i], -1);

        return solve(0, 0, n1, n2, s1, s2);
    }
}
