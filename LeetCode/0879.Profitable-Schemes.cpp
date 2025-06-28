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

// 

class Solution {
public:

    int mod = 1e9+7;
    int dp[102][102][102];

    int helper(int i, int n, int currProfit, int& minProfit, vector<int>& group, vector<int>& profit) {

        if(i==group.size() && n>=0 && currProfit == minProfit) return 1;
        if(n<0 || i==group.size()) return 0;

        if(dp[i][n][currProfit] != -1) return dp[i][n][currProfit];

        int take=0, notTake=0;
        notTake = helper(i+1,n,currProfit,minProfit,group,profit)%mod;
        take = helper(i+1,n-group[i],min(currProfit+profit[i],minProfit),minProfit,group,profit)%mod;

        return dp[i][n][currProfit] = (take+notTake)%mod;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return helper(0,n,0,minProfit,group,profit);
    }
};
