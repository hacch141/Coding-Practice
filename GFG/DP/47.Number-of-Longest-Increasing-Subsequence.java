// Number of Longest Increasing Subsequence

class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;

        int[] dp = new int[n];
        int[] cnt = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(cnt, 1);

        int lis = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (1 + dp[j] == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                    else if (1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                        cnt[i] = cnt[j];
                    }
                }
            }
            if (dp[i] == lis) {
                ans += cnt[i];
            } else if (dp[i] > lis) {
                lis = dp[i];
                ans = cnt[i];
            }
        }

        return ans;
    }
}
