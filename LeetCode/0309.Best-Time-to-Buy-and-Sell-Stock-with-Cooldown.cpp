// 309. Best Time to Buy and Sell Stock with Cooldown

// Rec
class Solution {
public:
    int dp[5001];

    int solve(int ind, int& n, vector<int>& prices) {
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int take = 0;
        for(int i = ind + 1; i < n; i++) {
            take = max(take, (prices[i] - prices[ind]) + solve(i + 2, n, prices));
        }
        int nottake = solve(ind + 1, n, prices);

        return dp[ind] = max(take, nottake);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n, prices);
    }
};

// DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;

        vector<int> dp(n, 0);
        dp[1] = max(dp[1], prices[1] - prices[0]);

        // sell on i day, buy on j day 
        for(int i = 2; i < n; i++) {
            // nottake
            dp[i] = dp[i - 1];
            // take
            for(int j = 0; j < i; j++) {
                int prev_profit = (j >= 2 ? dp[j - 2] : 0);
                dp[i] = max(dp[i], prices[i] - prices[j] + prev_profit);
            }
        }

        return dp[n - 1];
    }
};

// Memoization
class Solution {

private:
    int solve(int idx, int n, int buy, vector<int>& prices,vector<vector<long>>& dp) {
        if(idx >= n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy) {
            return dp[idx][buy] = max(-prices[idx]+solve(idx+1,n,0,prices,dp) , solve(idx+1,n,1,prices,dp));
        } else {
            return dp[idx][buy] = max( prices[idx]+solve(idx+2,n,1,prices,dp) , solve(idx+1,n,0,prices,dp));
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n+1, vector<long> (2,-1));
        return solve(0,n,1,prices,dp);
    }
};

// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n+2, vector<long> (2,0));

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy) {
                    dp[i][buy] = max(-prices[i]+dp[i+1][0] , dp[i+1][1]);
                }
                else {
                    dp[i][buy] = max( prices[i]+dp[i+2][1] , dp[i+1][0]);
                }
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
        vector<long> dp1(2,0), dp2(2,0), curr(2,0);

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy) {
                    curr[buy] = max(-prices[i]+dp1[0] , dp1[1]);
                }
                else {
                    curr[buy] = max( prices[i]+dp2[1] , dp1[0]);
                }
            }
            dp2 = dp1;
            dp1 = curr;
        }
        return dp1[1];
    }
};
