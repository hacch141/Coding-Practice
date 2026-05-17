// Partition Array for Maximum Sum

class Solution {
    int[] dp;

    public int solve(int ind, int n, int[] nums, int k) {
        if (ind >= n) return 0;

        if (dp[ind] != -1) return dp[ind];

        int mx = 0, ans = 0;
        for (int i = 0; i < k; i++) {
            if (ind + i >= n) break;
            mx = Math.max(mx, nums[ind + i]);
            ans = Math.max(ans, (i + 1) * mx + solve(ind + i + 1, n, nums, k));
        }

        return dp[ind] = ans;
    }

    public int maxSumAfterPartitioning(int[] nums, int k) {
        int n = nums.length;

        dp = new int[n];
        Arrays.fill(dp, -1);

        return solve(0, n, nums, k);
    }
}
