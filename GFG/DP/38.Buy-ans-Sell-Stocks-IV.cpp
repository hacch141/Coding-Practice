// Maximum Profit (K transaction)

// Memoization
class Solution {
public:
    int solve(int idx, int buy, int K, int& N, int A[], vector<vector<vector<int>>>& dp) {
        if(idx==N || K==0) return 0;
        if(dp[idx][buy][K] != -1) return dp[idx][buy][K];
        if(buy) {
            int Buy = -A[idx] + solve(idx+1,0,K,N,A,dp);
            int notbuy = 0 + solve(idx+1,1,K,N,A,dp);
            return dp[idx][buy][K] = max(Buy,notbuy);
        }
        int sell = A[idx] + solve(idx+1,1,K-1,N,A,dp);
        int notsell = 0 + solve(idx+1,0,K,N,A,dp);
        return dp[idx][buy][K] = max(sell,notsell);
    }

    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>> dp(N, vector<vector<int>> (2, vector<int> (K+1,-1)));
        return solve(0,1,K,N,A,dp);
    }
};


// Tabulation
class Solution {

public:

    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>> dp(N+1, vector<vector<int>> (2, vector<int> (K+1,0)));
        for(int idx=N-1; idx>=0; idx--) {
            for(int k=1; k<=K; k++) {
                int Buy = -A[idx] + dp[idx+1][0][k];
                int notbuy = 0 + dp[idx+1][1][k];
                dp[idx][1][k] = max(Buy,notbuy);
                
                int sell = A[idx] + dp[idx+1][1][k-1];
                int notsell = 0 + dp[idx+1][0][k];
                dp[idx][0][k] = max(sell,notsell);
            }
        }
        return dp[0][1][K];
    }
};



// Space Optimization
class Solution {

public:

    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<int>> prev(2, vector<int> (K+1,0));
        vector<vector<int>> curr(2, vector<int> (K+1,0));
        for(int idx=N-1; idx>=0; idx--) {
            for(int k=1; k<=K; k++) {
                int Buy = -A[idx] + prev[0][k];
                int notbuy = 0 + prev[1][k];
                curr[1][k] = max(Buy,notbuy);
                
                int sell = A[idx] + prev[1][k-1];
                int notsell = 0 + prev[0][k];
                curr[0][k] = max(sell,notsell);
            }
            prev = curr;
        }
        return curr[1][K];
    }
};
