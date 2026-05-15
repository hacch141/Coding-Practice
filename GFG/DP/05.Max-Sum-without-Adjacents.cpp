// Max Sum without Adjacents

// Memoization
class Solution {

    int solve(int n, int[] arr, int[] dp) {

        if (n == 0) return arr[0];

        if (n < 0) return 0;

        if (dp[n] != -1) return dp[n];

        int take = arr[n] + solve(n - 2, arr, dp);

        int notTake = solve(n - 1, arr, dp);

        return dp[n] = Math.max(take, notTake);
    }

    // Calculate the maximum sum without adjacent elements
    int findMaxSum(int[] arr, int n) {

        int[] dp = new int[n];

        for (int i = 0; i < n; i++) {
            dp[i] = -1;
        }

        return solve(n - 1, arr, dp);
    }
}
// T : O(N)
// S : O(N) + Stack Space


// =======================================================================


// Tabulation
class Solution {

    // Calculate the maximum sum without adjacent elements
    int findMaxSum(int[] arr, int n) {

        if (n == 1) return arr[0];

        int[] dp = new int[n];

        dp[0] = arr[0];

        dp[1] = Math.max(arr[0], arr[1]);

        for (int i = 2; i < n; i++) {

            int take = arr[i] + dp[i - 2];

            int notTake = dp[i - 1];

            dp[i] = Math.max(take, notTake);
        }

        return dp[n - 1];
    }
}
// T : O(N)
// S : O(N)


// =======================================================================


// Space Optimization
class Solution {

    // Calculate the maximum sum without adjacent elements
    int findMaxSum(int[] arr, int n) {

        if (n == 1) return arr[0];

        int prev2 = arr[0];

        int prev = Math.max(arr[0], arr[1]);

        for (int i = 2; i < n; i++) {

            int take = arr[i] + prev2;

            int notTake = prev;

            int curr = Math.max(take, notTake);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
}
// T : O(N)
// S : O(1)
