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
