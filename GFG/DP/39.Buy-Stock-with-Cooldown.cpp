// Buy Stock with Cooldown

// Memoization
class Solution{
    public:
    long long solve(int idx, int buy, vector<long long>&prices, int& n, vector<vector<long long>>& dp) {
        if(idx>=n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy) {
            long long Buy = -prices[idx] + solve(idx+1,0,prices,n,dp);
            long long notbuy = 0 + solve(idx+1,1,prices,n,dp);
            return dp[idx][buy] = max(Buy,notbuy);
        }
        long long sell = prices[idx] + solve(idx+2,1,prices,n,dp);
        long long notsell = 0 + solve(idx+1,0,prices,n,dp);
        return dp[idx][buy] = max(sell,notsell);
    }
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>> dp(n, vector<long long> (2,-1));
        return solve(0,1,prices,n,dp);
    }
};


// Tabulation
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>> dp(n+2, vector<long long> (2,0));
        for(int idx=n-1; idx>=0; idx--) {
            long long Buy = -prices[idx] + dp[idx+1][0];
            long long notbuy = 0 + dp[idx+1][1];
            dp[idx][1] = max(Buy,notbuy);
            long long sell = prices[idx] + dp[idx+2][1];
            long long notsell = 0 + dp[idx+1][0];
            dp[idx][0] = max(sell,notsell);
        }
        return dp[0][1];
    }
};
