// 300. Longest Increasing Subsequence

class Solution {
public:

    int solve(int i, int& n, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if(i == n) return 0;

        if(dp[i+1][prev+1] != -1) return dp[i+1][prev+1];

        int nottake = solve(i+1, n, prev, nums, dp);
        int take = 0;
        if(prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i+1, n, i, nums, dp);
        }

        return dp[i+1][prev+1] = max(take,nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n, -1, nums, dp);
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi = INT_MIN;

        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]) {
                    dp[i] = 1+dp[prev];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};
