// Recursion =====================================================
class Solution
{
    private:
    int solve(int n) {
        if(n==0 || n==1) return 1;
        int one = solve(n-1);
        int two = solve(n-2);
        return one + two;
    }
    
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        return solve(n);
    }
};


// Memoization =====================================================
class Solution
{
    int mod = (int)1e9+7;
    private:
    int solve(int n, vector<int> &dp) {
        if(dp[n] != -1) return dp[n];
        int one = solve(n-1,dp);
        int two = solve(n-2,dp);
        return dp[n] = (one + two)%mod;
    }
    
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1,-1);
        dp[0] = dp[1] = 1;
        solve(n,dp);
        return dp[n];
    }
};

// Tabulation =====================================================
class Solution
{
    int mod = (int)1e9+7;
    private:
    int solve(int n) {
        vector<int> dp(n+1,0);
        dp[0] = dp[1] = 1;
        for(int i=2; i<=n; i++) {
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        return dp[n];
    }
    
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        return solve(n);
    }
};

// space optimization =====================================================
class Solution
{
    int mod = (int)1e9+7;
    private:
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
    
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        return solve(n);
    }
};
