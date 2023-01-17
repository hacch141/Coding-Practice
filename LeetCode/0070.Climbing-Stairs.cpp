// 70. Climbing Stairs

class Solution {

private:
    int solve(int idx, vector<int>& dp) {
        if(dp[idx] != 0) return dp[idx];
        if(idx == 0 || idx == 1) return 1;
        int left = solve(idx-1,dp);
        int right = INT_MAX;
        if(idx > 1) {
            right = solve(idx-2,dp);
        }
        dp[idx] = left+right;
        return dp[idx];
    }

public:
    int climbStairs(int n) {
        if(n<=1) return n;
        vector<int> dp(n+1,0);
        solve(n,dp);
        return dp[n];
    }
};
