// 673. Number of Longest Increasing Subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int maxi = INT_MIN;
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]) {
                    dp[i] = 1+dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if(nums[prev]<nums[i] && 1+dp[prev]==dp[i]) {
                    cnt[i] += cnt[prev];
                }
                maxi = max(maxi,dp[i]);
            }
        }

        for(int i=0; i<n; i++) {
            if(dp[i] == maxi) {
                ans += cnt[i];
            }
        }

        return ans;
    }
};
