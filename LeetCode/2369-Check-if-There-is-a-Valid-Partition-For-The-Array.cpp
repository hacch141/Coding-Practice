// 2369. Check if There is a Valid Partition For The Array

class Solution {
public:
    bool solve(int ind, int n, vector<int>& nums, vector<int>& dp) {
        if(ind == n) return true;

        if(dp[ind] != -1) return dp[ind];

        bool f = false;

        if(ind + 1 < n && nums[ind] == nums[ind + 1]) {
            f |= solve(ind + 2, n, nums, dp);
        }

        if(ind + 2 < n && nums[ind] == nums[ind + 1] && nums[ind] == nums[ind + 2]) {
            f |= solve(ind + 3, n, nums, dp);
        }

        if(ind + 2 < n && nums[ind] + 1 == nums[ind + 1] && nums[ind + 1] + 1 == nums[ind + 2]) {
            f |= solve(ind + 3, n, nums, dp);
        }

        return dp[ind] = f;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, n, nums, dp);
    }
};
