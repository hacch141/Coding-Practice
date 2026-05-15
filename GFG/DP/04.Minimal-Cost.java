// Minimal Cost

// Memoization
class Solution {

    int solve(int n, int[] height, int k, int[] dp) {

        if (n == 0) return 0;

        if (dp[n] != -1) return dp[n];

        int minCost = Integer.MAX_VALUE;

        // Try all jumps
        for (int i = 1; i <= k; i++) {

            if (n - i >= 0) {

                int cost =
                        Math.abs(height[n] - height[n - i]) +
                        solve(n - i, height, k, dp);

                minCost = Math.min(minCost, cost);

            } else {
                break;
            }
        }

        return dp[n] = minCost;
    }

    public int minimizeCost(int[] height, int n, int k) {

        int[] dp = new int[n];

        for (int i = 0; i < n; i++) {
            dp[i] = -1;
        }

        return solve(n - 1, height, k, dp);
    }
}
// T : O(N * K) + Stack Space
// S : O(N)


// =======================================================================


// Tabulation
class Solution {

    public int minimizeCost(int[] height, int n, int k) {

        int[] dp = new int[n];

        dp[0] = 0;

        for (int i = 1; i < n; i++) {

            int minCost = Integer.MAX_VALUE;

            // Try all jumps
            for (int jump = 1; jump <= k; jump++) {

                if (i - jump >= 0) {

                    int cost =
                            Math.abs(height[i] - height[i - jump]) +
                            dp[i - jump];

                    minCost = Math.min(minCost, cost);
                }
            }

            dp[i] = minCost;
        }

        return dp[n - 1];
    }
}
// T : O(N * K)
// S : O(N)
