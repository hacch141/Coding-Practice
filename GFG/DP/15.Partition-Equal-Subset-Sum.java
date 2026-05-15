// Partition Equal Subset Sum

class Solution {
    public boolean canPartition(int[] nums) {
        int n = nums.length, sum = 0;

        for (int num : nums) sum += num;
        if (sum % 2 == 1) return false;
        
        boolean[] dp = new boolean[sum / 2 + 1];
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int target = sum / 2; target >= nums[i]; target--) {
                if (dp[target - nums[i]]) {
                    dp[target] = true;
                }
            }
        }

        return dp[sum / 2];
    }
}
