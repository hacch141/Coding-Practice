// Introduction to DP

class Solution {
  public:
  
    int mod = 1e9+7;
  
    long long solve(int n, vector<long long>& dp) {
        if(n<=1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (solve(n-1,dp) + solve(n-2,dp))%mod;
    }
    
    // Memoization
    long long int topDown(int n) {
        // code here
        vector<long long> dp(n+1, -1);
        return solve(n,dp);
    }
    // T : O(N)
    // S : O(N)
    
    
    // Tabulation
    long long int bottomUp(int n) {
        // code here
        long long prev2 = 0;
        long long prev = 1;
        if(n==0) return prev2;
        if(n==1) return prev;
        for(int i=2; i<=n; i++) {
            long long curr = (prev + prev2)%mod;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    // T : O(N)
    // S : O(1)
};
// https://takeuforward.org/data-structure/dynamic-programming-introduction/
