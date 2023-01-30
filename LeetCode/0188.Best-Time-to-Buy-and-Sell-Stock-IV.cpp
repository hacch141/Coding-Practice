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
