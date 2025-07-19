// 3366. Minimum Array Sum

class Solution {
public:
    int solve(int ind, int n, vector<int>& nums, int k, int op1, int op2, vector<vector<vector<int>>>& dp) {
        if(ind == n) return 0;

        if(dp[ind][op1][op2] != -1) return dp[ind][op1][op2];

        int skip = nums[ind] + solve(ind + 1, n, nums, k, op1, op2, dp);
        int one = INT_MAX, two = INT_MAX, both1 = INT_MAX, both2 = INT_MAX;
        if(op1 > 0) {
            one = ((nums[ind] + 1)/ 2) + solve(ind + 1, n, nums, k, op1 - 1, op2, dp);
        }
        if(op2 > 0 && nums[ind] >= k) {
            two = (nums[ind] - k) + solve(ind + 1, n, nums, k, op1, op2 - 1, dp);
        }
        if(op1 > 0 && op2 > 0) {
            int val1 = ((nums[ind] + 1) / 2) - k;
            if(val1 >= 0) both1 = val1 + solve(ind + 1, n, nums, k, op1 - 1, op2 - 1, dp);
            int val2 = nums[ind] - k;
            if(val2 >= 0) both2 = (val2 + 1) / 2 + solve(ind + 1, n, nums, k, op1 - 1, op2 - 1, dp);
        }
        return dp[ind][op1][op2] = min({one, two, both1, both2, skip});
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));
        return solve(0, n, nums, k, op1, op2, dp);
    }
};
