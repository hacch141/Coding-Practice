// 714. Best Time to Buy and Sell Stock with Transaction Fee

class Solution {
public:
    int solve(int ind, int n, bool buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if(ind == n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        int skip = solve(ind + 1, n, buy, prices, fee, dp);
        int not_skip = 0;
        if(buy) {
            not_skip = -(prices[ind] + fee) + solve(ind + 1, n, !buy, prices, fee, dp);
        }
        else {
            not_skip = prices[ind] + solve(ind + 1, n, !buy, prices, fee, dp);
        }
        return dp[ind][buy] = max(skip, not_skip);
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, n, true, prices, fee, dp);
    }
};
