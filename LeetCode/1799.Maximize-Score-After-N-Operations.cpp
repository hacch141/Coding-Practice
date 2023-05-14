// 1799. Maximize Score After N Operations

class Solution {
public:

    int solve(int op, int mask, vector<int>& nums, int& n, vector<vector<int>>& gcd, vector<int>& dp) {
        if(op>n) return 0;
        if(dp[mask] != -1) return dp[mask];

        for(int i=0; i<2*n; i++) {
            if(mask&(1<<i)) continue;
            for(int j=i+1; j<2*n; j++) {
                if(mask&(1<<j)) continue;
                int newmask = mask | (1<<i) | (1<<j);
                int score = op*gcd[i][j] + solve(op+1,newmask,nums,n,gcd,dp);
                dp[mask] = max(dp[mask],score);
            }
        }
        return dp[mask];
    }

    int maxScore(vector<int>& nums) {
        vector<int> dp(1<<14,-1);
        int m = nums.size();
        int n = m/2;
        vector<vector<int>> gcd(m, vector<int> (m,0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<m; j++) {
                gcd[i][j] = __gcd(nums[i],nums[j]);
            }
        }
        return solve(1,0,nums,n,gcd,dp);
    }
};
