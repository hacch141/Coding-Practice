// Longest Increasing Subsequence

class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;

        int[] dp = new int[n];
        Arrays.fill(dp, 1);

        int lis = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = Math.max(dp[i], 1 + dp[j]);
                }
            }
            lis = Math.max(lis, dp[i]);
        }

        return lis;
    }
}

class Solution {
    int[][] dp;

    public int solve(int ind, int prev, int n, int[] nums) {
        if (ind == n) return 0;

        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        
        int lis = solve(ind + 1, prev, n, nums);
        if (prev == -1 || nums[ind] > nums[prev]) {
            lis = Math.max(lis, 1 + solve(ind + 1, ind, n, nums));
        }
        else {
            lis = Math.max(lis, solve(ind + 1, prev, n, nums));
        }

        return dp[ind][prev + 1] = lis;
    }

    public int lengthOfLIS(int[] nums) {
        int n = nums.length;

        dp = new int[n][n + 1];
        for (int i = 0; i < n; i++) Arrays.fill(dp[i], -1);

        return solve(0, -1, n, nums);
    }
}
