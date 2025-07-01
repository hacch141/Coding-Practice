// 1799. Maximize Score After N Operations

class Solution {
public:
    int solve(int ind, int mask, int n, vector<int>& nums, vector<int>& dp) {
        if(mask == ((1 << n) - 1)) return 0;

        if(dp[mask] != -1) return dp[mask];

        int score = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int new_mask = mask;
                if(!(mask & (1 << i)) && !(mask & (1 << j))) {
                    new_mask |= (1 << i);
                    new_mask |= (1 << j);
                    score = max(score, ind * __gcd(nums[i], nums[j]) + solve(ind + 1, new_mask, n, nums, dp));
                }
            }
        }
        return dp[mask] = score;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp((1 << n), -1);
        return solve(1, 0, n, nums, dp);
    }
};
