// 198. House Robber

// DP
class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0, n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int prev2 = nums[0], prev = max(nums[1], nums[0]);
        for(int i=2; i<n; i++) {
            int curr = max(nums[i] + prev2, prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

// Rec
class Solution {
public:
    int dp[101];

    int solve(int ind, int& n, vector<int>& nums) {
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int take = nums[ind] + solve(ind + 2, n, nums);
        int nottake = solve(ind + 1, n, nums);
        return dp[ind] = max(take, nottake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, nums);
    }
};
