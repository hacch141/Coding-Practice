// 3129. Find All Possible Stable Binary Arrays I

class Solution {
    public int MOD = 1_000_000_007;
    public int[][][] dp;

    public int solve(int zero, int one, int limit, int prev) {
        if (zero == 0 && one == 0) return 1;

        if (dp[zero][one][prev] != -1) return dp[zero][one][prev];

        int curr = 0;
        if (prev != 0) {
            for (int i = 1; i <= Math.min(zero, limit); i++) {
                curr = (curr + solve(zero - i, one, limit, 0)) % MOD;
            }
        }

        if (prev != 1) {
            for (int i = 1; i <= Math.min(one, limit); i++) {
                curr = (curr + solve(zero, one - i, limit, 1)) % MOD;
            }
        }

        return dp[zero][one][prev] = curr;
    }

    public int numberOfStableArrays(int zero, int one, int limit) {
        dp = new int[zero + 1][one + 1][3];
        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }
        return solve(zero, one, limit, 2);
    }
}
