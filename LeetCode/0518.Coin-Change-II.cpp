// 518. Coin Change II

class Solution {
public:

    int solve(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(i==coins.size()) {
            return amount == 0 ? 1 : 0;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int nottake = solve(i+1,amount,coins,dp);

        int take = 0;
        if(coins[i] <= amount) {
            take = solve(i,amount-coins[i],coins,dp);
        }

        return dp[i][amount] = take+nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return solve(0,amount,coins,dp);
    }
};

// T : O(n*amount)
// S : O(n*amount + STACK)
