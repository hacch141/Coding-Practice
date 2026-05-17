// Palindrome Partitioning II

class Solution {
    public void expand(int l, int r, String s, int n, boolean[][] isPal) {
        if (l < 0 || r >= n) return;
        if (s.charAt(l) == s.charAt(r)) {
            isPal[l][r] = true;
            expand(l - 1, r + 1, s, n, isPal);
        }
    }

    int[] dp;

    public int solve(int ind, int n, boolean[][] isPal) {
        if (ind == n) return 0;

        if (dp[ind] != -1) return dp[ind];

        int ans = n;
        for (int i = ind; i < n; i++) {
            if (isPal[ind][i]) {
                ans = Math.min(ans, 1 + solve(i + 1, n, isPal));
            }
        }

        return dp[ind] = ans;
    }

    public int minCut(String s) {
        int n = s.length();
        boolean[][] isPal = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            expand(i, i, s, n, isPal);
            expand(i, i + 1, s, n, isPal);
        }

        dp = new int[n];
        Arrays.fill(dp, -1);

        return solve(0, n, isPal) - 1;
    }
}
