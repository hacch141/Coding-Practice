// Introduction to DP

class Solution {

    int mod = 1000000007;

    long solve(int n, long[] dp) {
        if (n <= 1) return n;

        if (dp[n] != -1) return dp[n];

        return dp[n] = (solve(n - 1, dp) + solve(n - 2, dp)) % mod;
    }

    // Memoization
    long topDown(int n) {
        long[] dp = new long[n + 1];

        for (int i = 0; i <= n; i++) {
            dp[i] = -1;
        }

        return solve(n, dp);
    }
    // T : O(N)
    // S : O(N)

    // Tabulation (Space Optimized)
    long bottomUp(int n) {

        long prev2 = 0;
        long prev = 1;

        if (n == 0) return prev2;
        if (n == 1) return prev;

        for (int i = 2; i <= n; i++) {
            long curr = (prev + prev2) % mod;

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
    // T : O(N)
    // S : O(1)
}
