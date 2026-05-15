// Subset Sum Problem

class Solution {
    public boolean isSubsetSum(int[] nums, int target) {
        int n = nums.length;

        boolean[] dp = new boolean[target + 1];
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            for (int t = target; t >= nums[i]; t--) {
                if (dp[t - nums[i]]) {
                    dp[t] = true;
                }
            }
        }

        return dp[target];
    }
}
