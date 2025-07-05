// 673. Number of Longest Increasing Subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(1 + dp[j] > dp[i]) {
                        dp[i] = 1 + dp[j];
                        cnt[i] = cnt[j];
                    }
                    else if(1 + dp[j] == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        int ans = 0;
        int lis = *max_element(dp.begin(), dp.end());
        for(int i = 0; i < n; i++) {
            if(dp[i] == lis) ans += cnt[i];
        }

        return ans;
    }
};
