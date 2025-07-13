// 1155. Number of Dice Rolls With Target Sum

class Solution {
public:

    int MOD = 1e9 + 7;

    int solve(int ind, int& n, int& k, int target, vector<vector<int>>& dp) {
        if(target < 0) return 0;
        if(ind == n) return target == 0;

        if(dp[ind][target] != -1) return dp[ind][target];
        
        int ans = 0;
        for(int i = 1; i <= k; i++) {
            ans = (ans + solve(ind+1, n, k, target - i, dp)) % MOD;
        }
        return dp[ind][target] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solve(0, n, k, target, dp);
    }
};

// Bottom Up
class Solution {
public:
    int MOD = 1e9 + 7;

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int f = 1; f <= k; f++) {
                    if (j - f >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - f]) % MOD;
                    }
                }
            }
        }

        return dp[n][target];
    }
};
