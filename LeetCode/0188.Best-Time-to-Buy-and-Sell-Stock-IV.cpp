class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(2, vector<long> (k+1,0)), curr(2, vector<long> (k+1,0));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                for(int cap=1; cap<=k; cap++) {
                    if(buy) {
                        curr[buy][cap] = max(-prices[i]+dp[0][cap] , dp[1][cap]);
                    } else {
                        curr[buy][cap] = max( prices[i]+dp[1][cap-1] , dp[0][cap]);
                    }
                }
            }
            dp = curr;
        }
        return dp[1][k];
    }
};



// Recursion
class Solution {

private:
    int solve(int idx, int transNo, vector<int>& prices, int n, int k) {
        if(idx==n || transNo==2*k) return 0;
        //buy 
        if(transNo%2 == 0) {
            return max(-prices[idx]+solve(idx+1,transNo+1,prices,n,k) , solve(idx+1,transNo,prices,n,k));
        } 
        //sell
        else { 
            return max( prices[idx]+solve(idx+1,transNo+1,prices,n,k) , solve(idx+1,transNo,prices,n,k));
        }
        return 0;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return solve(0,0,prices,n,k);
    }
};


// Memoization
class Solution {

private:
    int solve(int idx, int transNo, vector<int>& prices, int n, int k, vector<vector<long>>& dp) {
        if(idx==n || transNo==2*k) return 0;
        if(dp[idx][transNo] != -1) return dp[idx][transNo];
        //buy 
        if(transNo%2 == 0) {
            return dp[idx][transNo] = max(-prices[idx]+solve(idx+1,transNo+1,prices,n,k,dp) , solve(idx+1,transNo,prices,n,k,dp));
        } 
        //sell
        else { 
            return dp[idx][transNo] = max( prices[idx]+solve(idx+1,transNo+1,prices,n,k,dp) , solve(idx+1,transNo,prices,n,k,dp));
        }
        return 0;
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n, vector<long> (2*k,-1));
        return solve(0,0,prices,n,k,dp);
    }
};


// Tabulation
class Solution {

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n+1, vector<long> (2*k+1,0));

        for(int i=n-1; i>=0; i--) {
            for(int transNo=2*k-1; transNo>=0; transNo--) {
                // buy
                if(transNo%2 == 0) {
                    dp[i][transNo] = max(-prices[i]+dp[i+1][transNo+1] , dp[i+1][transNo]);
                }
                // sell
                else {
                    dp[i][transNo] = max( prices[i]+dp[i+1][transNo+1] , dp[i+1][transNo]);
                }
            }
        }
        return dp[0][0];
    }
};



// space optimization
class Solution {

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<long> dp(2*k+1,0), curr(2*k+1,0);

        for(int i=n-1; i>=0; i--) {
            for(int transNo=2*k-1; transNo>=0; transNo--) {
                // buy
                if(transNo%2 == 0) {
                    curr[transNo] = max(-prices[i]+dp[transNo+1] , dp[transNo]);
                }
                // sell
                else {
                    curr[transNo] = max( prices[i]+dp[transNo+1] , dp[transNo]);
                }
            }
            dp = curr;
        }
        return dp[0];
    }
};
