// Wildcard Pattern Matching

class Solution {
    int[][] dp;

    public boolean solve(int ind1, int ind2, int n1, int n2, String s1, String s2) {
        if (ind1 == n1 && ind2 == n2) return true;
        if (ind1 == n1) {
            while (ind2 < n2 && s2.charAt(ind2) == '*') ind2++;
            return ind2 == n2;
        }
        if (ind2 == n2) return false;

        if (dp[ind1][ind2] != -1) return dp[ind1][ind2] == 1 ? true : false;

        boolean ans = false;;
        if (s1.charAt(ind1) == s2.charAt(ind2) || s2.charAt(ind2) == '?') {
            ans = solve(ind1 + 1, ind2 + 1, n1, n2, s1, s2);
        }
        else if (s2.charAt(ind2) == '*') {
            ans = solve(ind1 + 1, ind2, n1, n2, s1, s2) | solve(ind1, ind2 + 1, n1, n2, s1, s2) | solve(ind1 + 1, ind2 + 1, n1, n2, s1, s2);
        }

        dp[ind1][ind2] = (ans == true ? 1 : 0);
        return ans;
    }

    public boolean isMatch(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();

        dp = new int[n1][n2];
        for (int i = 0; i < n1; i++) Arrays.fill(dp[i], -1);

        return solve(0, 0, n1, n2, s1, s2);
    }
}

