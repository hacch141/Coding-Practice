// 714. Best Time to Buy and Sell Stock with Transaction Fee

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> dp(2,0), curr(2,0);
        int n = prices.size();

        for(int i=n-1; i>=0; i--) {
            for(int buy=0; buy<=1; buy++) {
                if(buy) {
                    curr[buy] = max(-prices[i]-fee+dp[0] , dp[1]);
                }
                else {
                    curr[buy] = max( prices[i]+dp[1] , dp[0]);
                }
            }
            dp = curr;
        }
        return dp[1];
    }
};
