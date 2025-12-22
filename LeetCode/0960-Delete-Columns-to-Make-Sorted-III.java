// 960. Delete Columns to Make Sorted III

class Solution {
    public int solve(int ind, int prev, int n, String[] strs, int[][] dp) {
        if (ind == n) return 0;
        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        int nottake = 1 + solve(ind + 1, prev, n, strs, dp);
        int take = 0;
        for (int i = 0; i < strs.length; i++) {
            if (prev != -1 && strs[i].charAt(ind) < strs[i].charAt(prev)) {
                take = (int)1e9;
                break;
            }
        }
        if (take != 1e9) take = solve(ind + 1, ind, n, strs, dp);
        return dp[ind][prev + 1] = Math.min(take, nottake);
    }

    public int minDeletionSize(String[] strs) {
        int n = strs[0].length();
        int[][] dp = new int[n][n + 1];
        for (int i = 0; i < n; i++) Arrays.fill(dp[i], -1);
        return solve(0, -1, n, strs, dp);
    }
}
