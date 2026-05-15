// Partitions with Given Difference

class Solution {
    public int countPartitions(int[] nums, int diff) {
        // code here
        int n = nums.length, sum = 0;
        for (int num : nums) sum += num;
        
        if ((sum + diff) % 2 == 1) return 0;
        int target = (sum + diff) / 2;
        
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
    
    // s1 - s2 = diff
    // s1 + s2 = sum
    // 2*s1 = sum + diff
    // s1 = (sum + diff) / 2
}
