// Target Sum

class Solution {
    int[][] dp;

    public int solve(int ind, int n, int[] nums, int target, int curr) {
        if (ind == n) return curr == target ? 1 : 0;
        if (dp[ind][curr + 1000] !=  -1) return dp[ind][curr + 1000];
        int add = solve(ind + 1, n, nums, target, curr + nums[ind]);
        int rem = solve(ind + 1, n, nums, target, curr - nums[ind]);
        return dp[ind][curr + 1000] = add + rem;
    }

    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        dp = new int[n][2001];
        for (int i = 0; i < n; i++)
            Arrays.fill(dp[i], -1);
        return solve(0, n, nums, target, 0);
    }
}
