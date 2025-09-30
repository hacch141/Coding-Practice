// 2221. Find Triangular Sum of an Array

class Solution {
    public int triangularSum(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][n];
        for(int i = 0; i < n; i++) dp[0][i] = nums[i];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n - i; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1]) % 10;
            }
        }
        return dp[n - 1][0];
    }
}
