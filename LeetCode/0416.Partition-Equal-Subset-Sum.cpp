// 416. Partition Equal Subset Sum

// DP
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int target = sum / 2;

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= target; j++) {
                // nottale
                dp[i][j] = dp[i][j] | dp[i - 1][j];
                // take
                if(nums[i - 1] <= j) {
                    dp[i][j] = dp[i][j] | dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][target];
    }
};

// Rec
class Solution {
public:
    bool rec(int ind, int& n, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(target < 0) return false;
        if(ind == n) return target == 0;
        if(dp[ind][target] != -1) return dp[ind][target];
        bool f = false;
        f |= rec(ind + 1, n, target - nums[ind], nums, dp);
        f |= rec(ind + 1, n, target, nums, dp);
        return dp[ind][target] = f;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(auto &i : nums) sum += i;
        if(sum & 1) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return rec(0, n, target, nums, dp);
    }
};
