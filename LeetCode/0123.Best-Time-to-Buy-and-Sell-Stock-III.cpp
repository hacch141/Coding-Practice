// 123. Best Time to Buy and Sell Stock III


// Recursion
class Solution {

private:
    int solve(int idx, int n, int buy, int cap, vector<int>& prices) {
        if(idx==n || cap==0) return 0;
        long profit = 0;
        if(buy) {
            profit += max(-prices[idx]+solve(idx+1,n,0,cap,prices) , solve(idx+1,n,1,cap,prices));
        } else {
            profit += max( prices[idx]+solve(idx+1,n,1,cap-1,prices) , solve(idx+1,n,0,cap,prices));
        }
        return profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(0,n,1,2,prices);
    }
};


// Memoization
class Solution {

private:
    int solve(int idx, int n, int buy, int cap, vector<int>& prices, vector<vector<vector<long>>>& dp) {
        if(idx==n || cap==0) return 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        long profit = 0;
        if(buy) {
            profit += max(-prices[idx]+solve(idx+1,n,0,cap,prices,dp) , solve(idx+1,n,1,cap,prices,dp));
        } else {
            profit += max( prices[idx]+solve(idx+1,n,1,cap-1,prices,dp) , solve(idx+1,n,0,cap,prices,dp));
        }
        return dp[idx][buy][cap] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long>>> dp(n, vector<vector<long>> (2, vector<long> (3,-1)));
        return solve(0,n,1,2,prices,dp);
    }
};


// Tabulation
class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<long>>> dp(n+1, vector<vector<long>> (2, vector<long> (3,0)));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=2; cap++) {
                    if(buy) {
                        dp[i][buy][cap] = max(-prices[i]+dp[i+1][0][cap] , dp[i+1][1][cap]);
                    } else {
                        dp[i][buy][cap] = max( prices[i]+dp[i+1][1][cap-1] , dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};



// space optimization
class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(2, vector<long> (3,0)), curr(2, vector<long> (3,0));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=2; cap++) {
                    if(buy) {
                        curr[buy][cap] = max(-prices[i]+dp[0][cap] , dp[1][cap]);
                    } else {
                        curr[buy][cap] = max( prices[i]+dp[1][cap-1] , dp[0][cap]);
                    }
                }
            }
            dp = curr;
        }
        return dp[1][2];
    }
};
