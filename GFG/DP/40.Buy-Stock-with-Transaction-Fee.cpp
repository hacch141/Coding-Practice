// Buy Stock with Transaction Fee

// Memoization
class Solution{
    public:
    
    long long solve(int idx, int buy, vector<long long>&prices, int& n, int& fee, vector<vector<long long>>& dp) {
        if(idx==n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy) {
            long long Buy = -prices[idx] + solve(idx+1,0,prices,n,fee,dp);
            long long notbuy = 0 + solve(idx+1,1,prices,n,fee,dp);
            return dp[idx][buy] = max(Buy,notbuy);
        }
        long long sell = prices[idx] - fee  + solve(idx+1,1,prices,n,fee,dp);
        long long notsell = 0 + solve(idx+1,0,prices,n,fee,dp);
        return dp[idx][buy] = max(sell,notsell);
    }
    
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<vector<long long>> dp(n, vector<long long> (2,-1));
        return solve(0,1,prices,n,fee,dp);
    }
};



// Tabulation
class Solution{
    public:
    
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<vector<long long>> dp(n+1, vector<long long> (2,0));
        for(int idx=n-1; idx>=0; idx--) {
            long long Buy = -prices[idx] + dp[idx+1][0];
            long long notbuy = 0 + dp[idx+1][1];
            dp[idx][1] = max(Buy,notbuy);
            long long sell = prices[idx] - fee  + dp[idx+1][1];
            long long notsell = 0 + dp[idx+1][0];
            dp[idx][0] = max(sell,notsell);
        }
        return dp[0][1];
    }
};



// Space Optimization
class Solution{
    public:
    
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<long long> prev(2,0), curr(2,0);
        for(int idx=n-1; idx>=0; idx--) {
            long long Buy = -prices[idx] + prev[0];
            long long notbuy = 0 + prev[1];
            curr[1] = max(Buy,notbuy);
            long long sell = prices[idx] - fee  + prev[1];
            long long notsell = 0 + prev[0];
            curr[0] = max(sell,notsell);
            prev = curr;
        }
        return curr[1];
    }
};
