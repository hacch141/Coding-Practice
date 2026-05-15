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

class Solution {
    int[][] dp;
    
    // Function to calculate the number of subsets with a given sum
    public int solve(int ind, int n, int[] nums, int target) {
        if (target < 0) return 0;
        if (ind == n) return target == 0 ? 1 : 0;
        
        if (dp[ind][target] != -1) return dp[ind][target];
        
        int take = solve(ind + 1, n, nums, target - nums[ind]);
        int nottake = solve(ind + 1, n, nums, target);
        return dp[ind][target] = take + nottake;
    }
    
    public int perfectSum(int[] nums, int target) {
        // code here
        int n = nums.length;

        dp = new int[n][target + 1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }

        return solve(0, n, nums, target);
    }
}
