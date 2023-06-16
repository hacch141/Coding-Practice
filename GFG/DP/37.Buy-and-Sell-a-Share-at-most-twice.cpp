// Buy and Sell a Share at most twice

// Memoization
int solve(int idx, int buy, int cap, vector<int>&price,int& n, vector<vector<vector<int>>>& dp) {
    if(idx==n || cap==0) return 0;
    if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
    if(buy) {
        int Buy = -price[idx]+solve(idx+1,0,cap,price,n,dp);
        int notbuy = 0+solve(idx+1,1,cap,price,n,dp);
        return dp[idx][buy][cap] = max(Buy,notbuy);
    }
    int sell = price[idx]+solve(idx+1,1,cap-1,price,n,dp);
    int notsell = 0+solve(idx+1,0,cap,price,n,dp);
    return dp[idx][buy][cap] = max(sell,notsell);
}

int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3,-1)));
    return solve(0,1,2,price,n,dp);
}


// Tabulation
int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,0)));
    for(int idx=n-1; idx>=0; idx--) {
        for(int cap=1; cap<=2; cap++) {
            int Buy = -price[idx] + dp[idx+1][0][cap];
            int notbuy = 0 + dp[idx+1][1][cap];
            dp[idx][1][cap] = max(Buy,notbuy);
        
            int sell = price[idx] + dp[idx+1][1][cap-1];
            int notsell = 0 + dp[idx+1][0][cap];
            dp[idx][0][cap] = max(sell,notsell);
        }
    }
    return dp[0][1][2];
}


// Space Optimization
int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    vector<vector<int>> prev(2, vector<int> (3,0));
    vector<vector<int>> curr(2, vector<int> (3,0));
    for(int idx=n-1; idx>=0; idx--) {
        for(int cap=1; cap<=2; cap++) {
            int Buy = -price[idx] + prev[0][cap];
            int notbuy = 0 + prev[1][cap];
            curr[1][cap] = max(Buy,notbuy);
        
            int sell = price[idx] + prev[1][cap-1];
            int notsell = 0 + prev[0][cap];
            curr[0][cap] = max(sell,notsell);
        }
        prev = curr;
    }
    return curr[1][2];
}
