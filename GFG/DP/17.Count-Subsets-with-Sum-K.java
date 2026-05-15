// Perfect Sum Problem

class Solution {
    // Function to calculate the number of subsets with a given sum
    public int perfectSum(int[] nums, int target) {
        // code here
        int n = nums.length;
        
        int[] dp = new int[target + 1];
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int t = target; t >= nums[i]; t--) {
                if (dp[t - nums[i]] > 0) {
                    dp[t] += dp[t - nums[i]];
                }
            }
        }
        
        return dp[target];
    }
}
