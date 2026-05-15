// Geek Jump

// Memoization
class Solution {

    int solve(int n, int[] height, int[] dp) {

        if (n == 0) return 0;

        if (dp[n] != -1) return dp[n];

        int oneStep =
                Math.abs(height[n] - height[n - 1]) +
                solve(n - 1, height, dp);

        int twoStep = Integer.MAX_VALUE;

        if (n > 1) {
            twoStep =
                    Math.abs(height[n] - height[n - 2]) +
                    solve(n - 2, height, dp);
        }

        return dp[n] = Math.min(oneStep, twoStep);
    }

    public int minimumEnergy(int[] height, int n) {

        int[] dp = new int[n];

        for (int i = 0; i < n; i++) {
            dp[i] = -1;
        }

        return solve(n - 1, height, dp);
    }
}
// T : O(N)
// S : O(N)


// =======================================================================


// Tabulation
class Solution {

    public int minimumEnergy(int[] height, int n) {

        if (n == 1) return 0;

        int[] dp = new int[n];

        dp[1] = Math.abs(height[1] - height[0]);

        for (int i = 2; i < n; i++) {

            int jumpOne =
                    Math.abs(height[i] - height[i - 1]) +
                    dp[i - 1];

            int jumpTwo =
                    Math.abs(height[i] - height[i - 2]) +
                    dp[i - 2];

            dp[i] = Math.min(jumpOne, jumpTwo);
        }

        return dp[n - 1];
    }
}
// T : O(N)
// S : O(N)


// =======================================================================


// Space Optimization
class Solution {

    public int minimumEnergy(int[] height, int n) {

        if (n == 1) return 0;

        int prev2 = 0;
        int prev = Math.abs(height[1] - height[0]);

        for (int i = 2; i < n; i++) {

            int jumpOne =
                    Math.abs(height[i] - height[i - 1]) +
                    prev;

            int jumpTwo =
                    Math.abs(height[i] - height[i - 2]) +
                    prev2;

            int curr = Math.min(jumpOne, jumpTwo);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
}
// T : O(N)
// S : O(1)
