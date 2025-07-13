// 1269. Number of Ways to Stay in the Same Place After Some Steps

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int ind, int n, int steps, vector<vector<int>>& dp) {
        // not able to come on index 0 again
        if(ind > steps) return 0;
        if(steps == 0) return ind == 0;

        if(dp[ind][steps] != -1) return dp[ind][steps];

        int l = 0, r = 0, same = 0;
        same = solve(ind, n, steps - 1, dp);
        if(ind > 0) l = solve(ind - 1, n, steps - 1, dp);
        if(ind < n - 1) r = solve(ind + 1, n, steps - 1, dp);
        return dp[ind][steps] = ((l + r) % MOD + same) % MOD;
    }

    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(501, vector<int>(501, -1));
        return solve(0, arrLen, steps, dp);
    }
};
