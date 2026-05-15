// Count ways to reach the n'th stair

// Count ways to reach the n'th stair

// Memoization
class Solution {

    int mod = 1000000007;

    int solve(int n, int[] dp) {
        if (n <= 1) return 1;

        if (dp[n] != -1) return dp[n];

        int one = solve(n - 1, dp);
        int two = solve(n - 2, dp);

        return dp[n] = (one + two) % mod;
    }

    int countWays(int n) {

        int[] dp = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            dp[i] = -1;
        }

        dp[0] = dp[1] = 1;

        solve(n, dp);

        return dp[n];
    }
}
// T : O(N)
// S : O(N)


// ======================================================================


// Tabulation
class Solution {

    int mod = 1000000007;

    int solve(int n) {

        int[] dp = new int[n + 1];

        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }

        return dp[n];
    }

    int countWays(int n) {
        return solve(n);
    }
}
// T : O(N)
// S : O(N)


// ======================================================================


// Space Optimization
class Solution {

    int mod = 1000000007;

    int solve(int n) {

        if (n <= 1) return 1;

        int prev = 1;
        int prev2 = 1;

        for (int i = 2; i <= n; i++) {

            int curr = (prev + prev2) % mod;

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

    int countWays(int n) {
        return solve(n);
    }
}
// T : O(N)
// S : O(1)

// https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs/

// https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs/
