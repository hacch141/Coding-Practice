// 122. Best Time to Buy and Sell Stock II

// Recursion
class Solution {

private:
    int solve(int idx, int n, int buy, vector<int>& prices) {
        if(idx == n) return 0;
        long profit = 0;
        if(buy) {
            profit += max(-prices[idx]+solve(idx+1,n,0,prices) , 0 + solve(idx+1,n,1,prices));
        } else {
            profit += max( prices[idx]+solve(idx+1,n,1,prices) , 0 + solve(idx+1,n,0,prices));
        }
        return profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(0,n,1,prices);
    }
};


// Memoization
class Solution {

private:
    int solve(int idx, int n, int buy, vector<int>& prices, vector<vector<long>>& dp) {
        if(idx == n) return 0;
        long profit = 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy) {
            profit += max(-prices[idx]+solve(idx+1,n,0,prices,dp) , 0 + solve(idx+1,n,1,prices,dp));
        } else {
            profit += max( prices[idx]+solve(idx+1,n,1,prices,dp) , 0 + solve(idx+1,n,0,prices,dp));
        }
        return dp[idx][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n, vector<long>(2,-1));
        return solve(0,n,1,prices,dp);
    }
};


// Tabulation
class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n+1, vector<long>(2,-1));
        dp[n][0] = dp[n][1] = 0;

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                long profit = 0;
                if(buy) {
                    profit += max(-prices[i]+dp[i+1][0] , dp[i+1][1]);
                } else {
                    profit += max( prices[i]+dp[i+1][1] , dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};



// space optimization
class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<long> dp(2,0), curr(2,0);
        dp[0] = dp[1] = 0;

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                long profit = 0;
                if(buy) {
                    profit += max(-prices[i]+dp[0] , dp[1]);
                } else {
                    profit += max( prices[i]+dp[1] , dp[0]);
                }
                curr[buy] = profit;
            }
            dp = curr;
        }
        return dp[1];
    }
};
