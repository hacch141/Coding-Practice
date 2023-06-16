// Buy Stock 2

// Memoization
class Solution{
    public:
    
    long long solve(int idx, int buy, vector<long long>& prices, int& n, vector<vector<int>>& dp) {
        if(idx==n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy) {
            int Buy = -prices[idx] + solve(idx+1,0,prices,n,dp);
            int notbuy = 0+solve(idx+1,1,prices,n,dp);
            return dp[idx][buy] = max(Buy,notbuy);
        }
        int sell = prices[idx] + solve(idx+1,1,prices,n,dp);
        int notsell = 0+solve(idx+1,0,prices,n,dp);
        return dp[idx][buy] = max(sell,notsell);
    }
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return solve(0,1,prices,n,dp);
    }
};


// Tabulation
class Solution{
    public:
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<int>> dp(n+1, vector<int> (2,0));
        for(int idx=n-1; idx>=0; idx--) {
            int Buy = -prices[idx] + dp[idx+1][0];
            int notbuy = dp[idx+1][1];
            dp[idx][1] = max(Buy,notbuy);
            
            int sell = prices[idx] + dp[idx+1][1];
            int notsell = 0+dp[idx+1][0];
            dp[idx][0] = max(sell,notsell);
        }
        return dp[0][1];
    }
};


// Space Optimization
class Solution{
    public:
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<int> prev(2,0), curr(2,0);
        for(int idx=n-1; idx>=0; idx--) {
            int Buy = -prices[idx] + prev[0];
            int notbuy = prev[1];
            curr[1] = max(Buy,notbuy);
            
            int sell = prices[idx] + prev[1];
            int notsell = 0+prev[0];
            curr[0] = max(sell,notsell);
            prev = curr;
        }
        return curr[1];
    }
};
