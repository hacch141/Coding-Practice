// 494. Target Sum

class Solution {
public:
    int solve(int ind, int n, int curr_sum, vector<int>& nums, int target, vector<map<int,int>>& dp) {
        if(ind == n) return curr_sum == target;

        if(dp[ind].count(curr_sum)) return dp[ind][curr_sum];

        int add = solve(ind + 1, n, curr_sum + nums[ind], nums, target, dp);
        int minus = solve(ind + 1, n, curr_sum - nums[ind], nums, target, dp);

        return dp[ind][curr_sum] = add + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<map<int,int>> dp(n);
        return solve(0, n, 0, nums, target, dp);
    }
};
