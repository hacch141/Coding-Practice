// 486. Predict the Winner

class Solution {
public:
    int solve(int l, int r, bool player1, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        if(l > r) return 0;

        if(dp[l][r][player1] != -1) return dp[l][r][player1];

        if(player1) {
            int left = nums[l] + solve(l + 1, r, !player1, nums, dp);
            int right = nums[r] + solve(l, r - 1, !player1, nums, dp);
            return dp[l][r][player1] = max(left, right);
        }
        else {
            int left = solve(l + 1, r, !player1, nums, dp);
            int right = solve(l, r - 1, !player1, nums, dp);
            return dp[l][r][player1] = min(left, right);
        }
        return -1;
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(auto i : nums) sum += i;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return 2 * solve(0, n - 1, true, nums, dp) >= sum;
    }
};
