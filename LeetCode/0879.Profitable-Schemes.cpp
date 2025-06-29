// 879. Profitable Schemes

class Solution {
public:
    int MOD = 1e9 + 7;

    int solve(int ind, vector<int>& group, vector<int>& profit, int n, int curr_profit, int minProfit, vector<vector<vector<int>>>& dp) {
        if(n < 0) return 0;
        if(ind == group.size()) return curr_profit >= minProfit;

        int profitKey = min(curr_profit, minProfit);
        if(dp[ind][n][profitKey] != -1) return dp[ind][n][profitKey];

        int take = solve(ind + 1, group, profit, n - group[ind], curr_profit + profit[ind], minProfit, dp);
        int not_take = solve(ind + 1, group, profit, n, curr_profit, minProfit, dp);

        return dp[ind][n][profitKey] = (take + not_take) % MOD;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(group.size(), vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return solve(0, group, profit, n, 0, minProfit, dp);
    }
};
