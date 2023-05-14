// Memoization 
class Solution
{
    public:
    int mod = 1e9+7;
    
    int solve(int n, vector<int> &dp) {
        if(dp[n] != -1) return dp[n];
        int one = solve(n-1,dp);
        int two = solve(n-2,dp);
        return dp[n] = (one + two)%mod;
    }
    
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1,-1);
        dp[0] = dp[1] = 1;
        solve(n,dp);
        return dp[n];
    }
};
// T : O(N)
// M : O(N)

// =======================================================================================

// Tabulation
class Solution
{
    public:
    int mod = 1e9+7;

    int solve(int n) {
        vector<int> dp(n+1,0);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        return dp[n];
    }
    
    int countWays(int n) {
        // your code here
        return solve(n);
    }
};
// T : O(N)
// M : O(N)

// space optimization 
class Solution
{
    public:
    int mod = 1e9+7;
    int solve(int n) {
        int prev = 1;
        int prev2 = 1;
        for(int i=2; i<=n; i++) {
            int curr = (prev+prev2)%mod;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    
    int countWays(int n) {
        // your code here
        return solve(n);
    }
};
// T : O(N)
// M : O(1)
