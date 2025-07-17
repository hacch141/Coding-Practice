// 3202. Find the Maximum Length of Valid Subsequence II

// class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int rem = 0; rem < k; rem++) {
            vector<int> dp(k, 0);
            for(int i = 0; i < n; i++) {
                int r = nums[i] % k;
                int l = (rem - r + k) % k;
                dp[r] = 1 + dp[l];
            }
            ans = max(ans, *max_element(dp.begin(), dp.end()));
        }
        return ans;
    }
};
